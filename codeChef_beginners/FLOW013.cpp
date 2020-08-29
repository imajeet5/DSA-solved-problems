//Valid Triangles
#include <bits/stdc++.h>

using namespace std;

bool validTringle(int a, int b, int c)
{
    if (a + b + c == 180)
    {
        return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        string result = validTringle(a, b, c) ? "YES" : "NO";
        cout << result << endl;
    }
    return 0;
}