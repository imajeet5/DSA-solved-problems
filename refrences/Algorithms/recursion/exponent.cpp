// Exponent (M)^n

#include <iostream>

using namespace std;

int pow(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return m * pow(m, n - 1);
}

int powFast(int m, int n)
{
    if (n == 0)
        return 1; 
    if (n % 2 == 0)
        return pow(m * m, n / 2);
    else
        return m * pow(m * m, (n - 1) / 2);
}

int main(int argc, char const *argv[])
{
    int x{};
    cout << "Enter a integer" << endl;
    cin >> x;
    cout << "Result: " << powFast(2, x) << endl;
    return 0;
}
