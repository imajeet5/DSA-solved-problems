// e^x = 1 + x/1 + (x^2)/2! + (x^3)/3! + (x^4)/4! + ........n terms

#include <iostream>
#include <iomanip>

using namespace std;

double e(int x, int n)
{
    static double p = 1, f = 1;
    double r;
    if (n == 0)
    {
        return 1;
    }

    r = e(x, n - 1);
    // this code will be executed at the return time
    p = p * x;
    f = f * n;
    return r + (p / f);
}

// using Horner's rule
double e_horner_loops(int x, int n)
{
    double r = 1;
    for (; n > 0; n--)
    {
        r = 1 + ((double)x / n) * r;
    }
    return r;
}

double e_horner_recursion(int x, int n)
{
    static double r = 1;
    if (n == 0)
        return r;
    r = 1 + ((double)x / n) * r;
    return e_horner_recursion(x, n - 1);
}

int main(int argc, char const *argv[])
{
    int x{};
    cout << "Enter a integer" << endl;
    cin >> x;
    cout << std::setprecision(100) << "Result: " << e_horner_recursion(1, x) << endl;
    return 0;
}
