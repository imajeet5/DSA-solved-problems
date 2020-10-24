#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void reverseWords(string str)
{
    vector<string> vec;
    string temp = "";
    for (auto it : str)
    {
        if (it == '.')
        {
            vec.push_back(temp);
            temp = "";
        }
        else
        {
            temp += it;
        }
    }
    vec.push_back(temp);
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        if (i == 0)
            cout << vec[i];
        else
            cout << vec[i] << ".";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    freopen("_input.txt", "r", stdin);
    int t = 0;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        reverseWords(s);
    }
    return 0;
}

/*
2
i.like.this.program.very.much
pqr.mno
*/