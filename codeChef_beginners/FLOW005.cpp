//Smallest Numbers of Notes
#include <bits/stdc++.h>

using namespace std;

const vector<int> changes{100, 50, 10, 5, 2, 1};

int getNumberOfNotes(int num)
{
    int total = 0;
    for (auto c : changes)
    {
        total += num / c;
        num = num % c;
    }
    return total;
}

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    while (n--)
    {
        int a = 0;
        cin >> a;
        cout << getNumberOfNotes(a) << endl;
    }
    return 0;
}