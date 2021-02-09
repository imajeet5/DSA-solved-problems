#include <bits/stdc++.h>

using namespace std;



int nCr(int n, int r) {
    double result = 1;
    for (int i = 1; i <= r; i++) {
        result *= (n - r + 1) / i;
    }

    return (int)result;
}


int main(int argc, char const* argv[]) {
    int x{};
    cout << "Enter a integer" << endl;
    cin >> x;
    cout << "Result: " << x << endl;
    return 0;
}