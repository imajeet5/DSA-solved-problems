// Reverse the Number

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
        reverse(num.begin(), num.end());
        cout << num << endl;
    }
    return 0;
}