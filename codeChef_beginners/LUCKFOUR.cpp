//Lucky Four
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
        int counter = 0;
        for (auto s : num)
        {
            if ((s - '0') == 4)
            {
                counter++;
            }
        }
        cout << counter << endl;
    }
    return 0;
}