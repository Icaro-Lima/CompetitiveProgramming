#include <bits/stdc++.h>

using namespace std;

long double dist(int x1, int y1, int x2, int y2) {
	return sqrtl(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
	int r1, x1, y1, r2, x2, y2;
	while (cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2) {	
		int diff = r1 - r2;
		
		// Se a distancia entre os centros for menor ou igual a
		// diferença entre o raio desenhado e o raio da flor de fogo.
		if (dist(x1, y1, x2, y2) <= diff) {
			cout << "RICO" << endl;
		} else {
			cout << "MORTO" << endl;
		}
	}
}
