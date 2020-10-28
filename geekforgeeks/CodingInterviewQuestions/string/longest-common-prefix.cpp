#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool charAreEqual(vector<string> arr, int j)
{

    char c = arr[0][j];
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        if (c != arr[i][j])
            return false;
    }
    return true;
}

string longestCommonPrefix(vector<string> arr)
{
    int min_len = INT_MAX;
    string ans = "";
    for (auto it : arr)
        min_len = min(min_len, (int)it.length());

    for (int i = 0; i < min_len; i++)
    {
        if (charAreEqual(arr, i))
        {
            ans += arr[0][i];
        }
    }

    if (ans.size() == 0)
    {
        ans = "-1";
    }

    return ans;
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
        vector<string> arr(n);
        string str;
        for (int i = 0; i < n; i++)
        {
            cin >> str;
            arr[i] = str;
        }

        cout << longestCommonPrefix(arr) << endl;
    }
    return 0;
}

/*
2
4
geeksforgeeks geeks geek geezer
3
apple ape april
*/