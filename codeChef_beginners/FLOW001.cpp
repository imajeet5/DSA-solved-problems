#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int cases = 0;
    int *sums = nullptr;
    cin >> cases;
    sums = new int[cases];
    for (int i = 0; i < cases; i++)
    {
        int a, b;
        cin >> a >> b;
        sums[i] = a + b;
    }
    for (int i = 0; i < cases; i++)
    {
        cout << sums[i] << endl;
    }
    return 0;
}