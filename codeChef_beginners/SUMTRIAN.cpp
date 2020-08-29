//Sums in a Triangle

#include <bits/stdc++.h>
#define REP(i, a, n) for (i = a; i < n; i++)
//#define rep(i, n) REP(i, 0, n)

using namespace std;

void printVec(std::vector<int> const &a);

void printVec(std::vector<int> const &a)
{

    for (int i = 0; i < a.size(); i++)
        std::cout << a.at(i) << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        vector<int> columns(size, 0);
        vector<vector<int>> tringle(size, columns);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cin >> tringle[i][j];
            }
        }
        int r = 0, c = 0;
        int sum = tringle[r][c];
        for (r = 1; r < size; r++)
        {
            // immediate below row is greater
            if (tringle[r][c] > tringle[r][c + 1])
            {
                sum += tringle[r][c];
            }
            else
            {
                sum += tringle[r][c + 1];
                c++;
            }
        }

        cout << sum << endl;
    }
    return 0;
}