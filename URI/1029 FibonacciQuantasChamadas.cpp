#include <bits/stdc++.h>

using namespace std;

int icount = 0;

long long fibonacci(int n) {
    icount++;

    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        icount = 0;
        long long result = fibonacci(n);

        cout << "fib(" << n << ") = " << icount - 1 << " calls = " << result << endl;
    }
}