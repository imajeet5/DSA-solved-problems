#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        vector<int> V;
        for (int j = 0, p = 0, m; j < n; j++)
        {
            V.push_back(0);
            for (int k = 0; k <= j; k++)
            {
                cin >> m;
                int t = V[k];
                V[k] = max(p, t) + m;
                p = t;
            }
        }
        cout << *max_element(V.begin(), V.end()) << "\n";
    }
}
