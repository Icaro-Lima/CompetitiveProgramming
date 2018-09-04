#include <bits/stdc++.h>

using namespace std;

struct Fib {
	long long value;
	int calls;
};

Fib compute(Fib dp[], int x) {
	if (dp[x].value == -1) {
		Fib a = compute(dp, x - 1);
		Fib b = compute(dp, x - 2);
		
		dp[x].calls = a.calls + b.calls + 2;
		dp[x].value = a.value + b.value;
	}
		
	return dp[x];
}

int main() {
	int n;
	cin >> n;
	
	Fib fibs[39 + 1];
	fibs[0].value = 0; fibs[0].calls = 0;
	fibs[1].value = 1; fibs[1].calls = 0;
	
	memset(fibs + 2, -1, (40 - 2) * sizeof(Fib));

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		
		Fib fib = compute(fibs, x);
		
		cout << "fib(" << x << ") = " << fib.calls << " calls = " << fib.value << endl;
	}
	
	return 0;
}
