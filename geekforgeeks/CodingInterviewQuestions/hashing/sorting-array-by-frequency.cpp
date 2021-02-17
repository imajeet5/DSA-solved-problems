#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void sortByFrequency(vector<int> arr)
{
    map<int, int> freq;
    map<int, set<int>> freq_rev;

    for (int i = 0; i < arr.size(); i++)
    {
        freq[arr[i]]++;
    }
    for (auto it : freq)
    {
        freq_rev[it.second].insert(it.first);
    }

    map<int, set<int>>::reverse_iterator it;

    for (it = freq_rev.rbegin(); it != freq_rev.rend(); it++)
    {
        for (auto s : it->second)
        {
            for (int i = 0; i < it->first; i++)
            {
                cout << s << " ";
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    // freopen("_input.txt", "r", stdin);
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            arr.push_back(num);
        }
        sortByFrequency(arr);
         cout << endl;
    }
    return 0;
}

/** 
 * 2
5
5 5 4 6 4
5
9 9 9 2 5
 */