//Chef and Remissness
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cout << max(a, b) << " " << a + b << endl;
    }
    return 0;
}