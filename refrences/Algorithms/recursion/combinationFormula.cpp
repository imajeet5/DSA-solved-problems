#include <iostream>

using namespace std;

int fact(int n);

// Using pascal tringle
int C_PascalT(int n, int r)
{
    if (r == 0 || n == r)
        return 1;
    return C_PascalT(n - 1, r - 1) + C_PascalT(n - 1, r);
}

int comb(float n, int r)
{
    if (r == 0 || r == n)
        return 1;
    else
        return (n / r) * comb(n - 1, r - 1);
}

int combinations(int n, int r)
{
    int t1, t2, t3;
    t1 = fact(n);
    t2 = fact(r);
    t3 = fact(n - r);
    return t1 / (t2 * t3);
}

int fact(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * fact(n - 1);
}

int main(int argc, char const *argv[])
{
    // int x{};
    // cout << "Enter a integer" << endl;
    // cin >> x;
    cout << "Result: " << C_PascalT(10, 3) << endl;
    return 0;
}
