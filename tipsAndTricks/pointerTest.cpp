#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int x = 10;
    int *y;
    y = &x;
    // same statement can also be written as
    // int *y = &x;

    *y = 20;
    cout << x << endl;
    cout << &x << endl;
    cout << *y << endl;
    cout << y << endl;

    return 0;
}