#include <bits/stdc++.h>

using namespace std;

// using two pointers
class Solution1
{
public:
    string removeDuplicates(string S)
    {
        int i = 0, n = S.size();
        // now what we do is keep two pointer i and j.
        // j will be the iterator and i will follow. If i current character is same as the last character
        // we will move back i by 2, i.e. skipping the duplicate elements
        for (int j = 0; j < n; j++, i++)
        {
            S[i] = S[j];

            if (i > 0 && S[i] == S[i - 1])
            {

                i -= 2;
            }
        }

        return S.substr(0, i);
    }
};

// Using Stack
class Solution2
{
public:
    string removeDuplicates(string S)
    {
        string res = "";
        for (auto c : S)
        {
            if (res.size() && c == res.back())
            {
                res.pop_back();
            }
            else
            {
                res.push_back(c);
            }
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    int x{};
    cout << "Enter a integer" << endl;
    cin >> x;
    cout << "Result: " << x << endl;
    return 0;
}