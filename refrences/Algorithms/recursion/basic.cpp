#include <iostream>

using namespace std;

// this will print the first value first
void printingInExecutionTime(int n, int i = 0)
{
    if (i > n)
    {
        printf("Recursion: printingInExecutionTime\n");
        return;
    }
    printf("%d\n", i);
    printingInExecutionTime(n, i + 1);
}

// this will print the last value first
void printingAtReturnTime(int n, int i = 0)
{
    if (i > n)
    {
        printf("Recursion: printingAtReturnTime\n");
        return;
    }

    printingAtReturnTime(n, i + 1);
    printf("%d\n", i);
}

int main(int argc, char const *argv[])
{
    int x{};
    cout << "Enter a integer" << endl;
    cin >> x;
    cout << endl;
    printingInExecutionTime(x);
    cout << endl;
    printingAtReturnTime(x);
    return 0;
}
