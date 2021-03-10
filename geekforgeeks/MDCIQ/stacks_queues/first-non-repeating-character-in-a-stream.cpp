#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void fNRCharXX(string s)
{
    set<char> existing;
    queue<char> lastNR;

    for (int i = 0; i < s.size(); i++)
    {
        if (existing.find(s[i]) == existing.end())
        {
            existing.insert(s[i]);
            lastNR.push(s[i]);
            cout << lastNR.front() << " ";
        }
        else
        {
            lastNR.pop();
            if (lastNR.empty())
            {
                cout << -1 << " ";
            }
            else
            {
                cout << lastNR.front() << " ";
            }
        }
    }
}

char fNRChar(string s)
{
    vector<int> charMap(256, 0);
    for (auto c : s)
    {
        charMap[c]++;
    }
    for (auto c : s)
    {
        if (charMap[c] == 1)
        {
            return c;
        }
    }

    return '0';
}

void fNRChar2(string s)
{
    queue<char> q;
    unordered_map<char, int> freq;
    string ans;
    for (auto c : s)
    {
        q.push(c);
        freq[c]++;
        if (freq[q.front()] == 1)
        {
            cout << q.front() << " ";
        }
        else
        {
            while (freq[q.front()] != 1 && !q.empty())
            {
                q.pop();
            }
            if (!q.empty())
                cout << q.front() << " ";
            else
                cout << -1 << " ";
        }
    }
    cout << endl;
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
        string s;
        for (int i = 0; i < n; i++)
        {
            char c;
            cin >> c;
            s += c;
            // char ans = fNRChar(s);
            // if (ans != '0')
            // {
            //     cout << ans << " ";
            // }
            // else
            // {
            //     cout << -1 << " ";
            // }
        }
        fNRChar2(s);
    }
    return 0;
}