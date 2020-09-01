#include <iostream>

using namespace std;

int fun(int n)
{
    if (n > 0)
    {
        return fun(n - 1) + n;
    };
    return 0;
}

int funWithStatic(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x++;
        return funWithStatic(n - 1) + x;
    };
    return 0;
}

int main(int argc, char const *argv[])
{
    int x{};
    cout << "Enter a integer" << endl;
    cin >> x;
    cout << "Result: " << funWithStatic(x) << endl;
    return 0;
}
