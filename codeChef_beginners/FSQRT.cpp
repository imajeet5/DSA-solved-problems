//Finding Square Roots
#include <bits/stdc++.h>

using namespace std;

int getSqrt(int num)
{
    int result;
    result = sqrt(num);
    return result;
}

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    while (n--)
    {
        int num;
        cin >> num;
        cout << getSqrt(num) << endl;
    }
    return 0;
}