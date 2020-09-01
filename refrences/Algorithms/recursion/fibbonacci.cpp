#include <iostream>
#include <vector>

using namespace std;

int counter = 0;

int fib_recursion(int n)
{

    counter++;
    if (n <= 1)
    {
        return n;
    }
    return fib_recursion(n - 2) + fib_recursion(n - 1);
}

int fib_loops(int n)
{
    int t0 = 0, t1 = 1, s = 0;
    for (int i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int fib_memoization(int n)
{
    counter++;

    static vector<int> valueStore(n + 1, -1);
    if (n <= 1)
    {
        valueStore.at(n) = n;
        return n;
    }
    // value of the successive recursive is called is cached in the array using the given condition, then sum of the last two element of the array is returned
    if (valueStore.at(n - 2) == -1)
        valueStore.at(n - 2) = fib_memoization(n - 2);
    if (valueStore.at(n - 1) == -1)
        valueStore.at(n - 1) = fib_memoization(n - 1);
    valueStore.at(n) = valueStore.at(n - 2) + valueStore.at(n - 1);
    return valueStore.at(n);
}

int main(int argc, char const *argv[])
{
    int x{};
    cout << "Enter a integer" << endl;
    cin >> x;
    cout << "Result: " << fib_memoization(x) << endl;
    cout << "times function called " << counter++ << endl;
    return 0;
}
