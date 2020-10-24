#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

// I have tried different approaches but didn't work out

bool isPalindrome(string str, int s, int e)
{
    while (s <= e)
    {
        if (str[s] != str[e])
        {
            return false;
        }
        s++;
        e--;
    }
    return true;
}

void printSubString(string str, int s, int e)
{
    for (int i = s; i <= e; i++)
    {
        cout << str[i];
    }
}
string getSubString(string str, int s, int e)
{
    string substr;
    for (int i = s; i <= e; i++)
    {
        substr.push_back(str[i]);
    }
    return substr;
}

void longestPalindrome1(string &str)
{
    int s = 0;
    int e = str.length() - 1;
    int flag = true;
    while (e >= 0)
    {
        if (isPalindrome(str, s, e))
        {
            printSubString(str, s, e);
            return;
        }
        e--;
    }
    e = str.length() - 1;
    while (s <= e)
    {
        if (isPalindrome(str, s, e))
        {
            printSubString(str, s, e);
            return;
        }
        s++;
    }
}

int main(int argc, char const *argv[])
{
    // freopen("_input.txt", "r", stdin);
    string str = "vnrtysfrzrmzlygfv";
    longestPalindrome1(str);
    return 0;
    int t = 0;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        longestPalindrome1(str);
        cout << endl;
    }
    return 0;
}

/*
rfkqyuqfjkxy
*/