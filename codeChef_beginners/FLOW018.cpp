#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    while (n--)
    {
        int num;
        cin >> num;
        int fact = 1;
        for (int i = 2; i <= num; i++)
        {
            fact *= i;
        }
        cout << fact << endl;
    }
    return 0;
}