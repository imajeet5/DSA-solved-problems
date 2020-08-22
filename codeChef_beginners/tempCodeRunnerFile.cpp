#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    while (n--)
    {
        string num;
        getline(cin >> ws, num);
        int last = num.at(num.size() - 1) - '0';
        int first = num.at(0) - '0';
        cout << first + last << endl;
    }
    return 0;
}