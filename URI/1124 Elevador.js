var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

lines.some(function (line) {
	values = line.split(' ').map(x => Number(x));
	
	if (values.reduce((acc, val) => acc + val, 0) === 0) return true;
	
	const width = Math.max(values[0], values[1]);
	const height = Math.min(values[0], values[1]);
	const r1 = values[2];
	const r2 = values[3];
	
	const pointA = { x: r1, y: r1 };
	const pointB = { x: width - r2, y: height - r2 };
	
	const dist = pointDistance(pointA, pointB);
	
	if (width >= r1 && height >= r1 && width >= r2 && height >= r2 && pointA.x + r1 <= width && pointA.y + r1 <= height && pointB.x - r2 >= 0 && pointB.y - r2 >= 0)
		if (dist >= r1 + r2) console.log('S');
		else console.log('N');
	else
		console.log('N');
		
	return false;
});

function pointDistance(a, b) {
	return Math.sqrt(Math.pow(a.x - b.x, 2) + Math.pow(a.y - b.y, 2));
}
