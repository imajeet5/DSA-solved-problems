#include <bits/stdc++.h>

using namespace std;

void printVec(std::vector<int> const &a)
{

    for (int i = 0; i < a.size(); i++)
        cout << a.at(i) << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int counter{0};
    vector<int> A{0,2,6,6};
    sort(begin(A), end(A), greater<int>());
    do
    {
        printVec(A);

        if ((A[0] < 2 || (A[0] == 2 && A[1] < 4)) && A[2] < 6 && counter == 0)
        {
            cout << "====================================" << endl;
            printVec(A);
            cout << "====================================" << endl;
            counter++;
        }

    } while (prev_permutation(begin(A), end(A)));

    cout << "total " << counter << endl;
    return 0;
}