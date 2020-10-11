#include <bits/stdc++.h>

using namespace std;

// time complexity is 2^n
int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}

// time complexity is O(n)

int fib2(int n, int *a)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    if (a[n] != 0)
    {
        return a[n];
    }
    int output = fib2(n - 1, a) + fib2(n - 2, a);
    a[n] = output; // store for future use
    return output;
}

int fib3(int n)
{
    int *arr = new int[n + 1];

    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    int output = arr[n];

    delete[] arr;

    return arr[n];
}

int fib4(int n)
{
    int a = 0;
    int b = 1;
    int c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = 0;
    }

    cout << fib4(n) << endl;
    cout << fib3(n) << endl;
    cout << fib2(n, arr) << endl;
    cout << fib(n) << endl;
    return 0;
}