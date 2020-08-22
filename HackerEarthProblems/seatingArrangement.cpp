#include <iostream>

using namespace std;

void printSeatName(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if ((arr[i] + 1) % 3 == 0)
        {
            cout << arr[i + 3] << " MS" << endl;
        }
        if (arr[i] % 6 == 0 || (arr[i] - 1) % 6 == 0)
        {
            if ((arr[i] - 1) % 6 == 0)
            {
                cout << arr[i] - 1 << " WS" << endl;
            }
            if (arr[i] % 6 == 0)
            {
                cout << arr[i] + 1 << " WS" << endl;
            }
        }
        if ((arr[i] - 3) % 6 == 0 || (arr[i] - 4) % 6 == 0)
        {
            if ((arr[i] - 4) % 6 == 0)
            {
                cout << arr[i] + 5 << " AS" << endl;
            }
            if ((arr[i] - 3) % 6 == 0)
            {
                cout << arr[i] + 7 << " AS" << endl;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int testCases{};
    int *values{nullptr};
    cin >> testCases;
    values = new int[testCases];
    for (int i = 0; i < testCases; i++)
    {
        cin >> values[i];
    };
    printSeatName(values, testCases);

    return 0;
}

/*
void getSeatName(int *arr, int size)
{
    for (int i = 1; i <= 108; i++)
    {
        if ((i + 1) % 3 == 0)
        {
            cout << i << " MS" << endl;
        }
        if (i % 6 == 0 || (i - 1) % 6 == 0)
        {
            cout << i << " WS" << endl;
        }
        if ((i - 3) % 6 == 0 || (i - 4) % 6 == 0)
        {
            cout << i << " AS" << endl;
        }
    }
}


*/