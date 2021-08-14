#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

// we have to return the logest substring length without repeating characters
// abcaabcdba  or abcabcbb

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxLen = 1;
        for (int i = 0; i < s.size(); i++)
        {
            unordered_map<char, int> exist;
            int len = 0;
            for (int j = i; j < s.size(); j++)
            {
                // if the element already exist in the array
                if (exist[s[j]])
                {
                    break;
                }
                exist[s[j]]++;
                len++;
            }

            if (len > maxLen)
            {
                maxLen = len;
            }
        }

        return maxLen;
    }
};

// have flaw in this solution
class SolutionOptimized
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0, j = 0;
        int mlen = 0, len = 0;
        unordered_set<char> exist;
        while (j < s.size())
        {
            char curr = s[j];
            mlen = max(len, mlen);
            // if current element is not in the set

            if (exist.find(curr) == exist.end())
            {
                // we will increase the window size
                // add it to set, increase the j position and len
                exist.insert(curr);
                j++;
                len++;
            }
            else
            {
                // if the element is in the set
                // we will decrease the window size by increasing the value of i and
                // removing the element from the set
                while (exist.find(curr) != exist.end())
                {

                    char c = s[i];
                    exist.erase(c);
                    i++;
                    len--;
                }
            }
        }
        mlen = max(len, mlen);
        return mlen;
    }
};

class SolutionOptimized2
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0, j = 0, len = 0;
        unordered_map<char, int> exist;
        while (j < s.size())
        {
            char curr = s[j];
            //if element exist in the map
            // the we will either jump the left or if index is before the left the left will stay at the same position
            if (exist.find(curr) != exist.end())
            {
                i = max(exist[curr] + 1, i);
            }

            // update or add the current element in the map
            exist[curr] = j;
            len = max(len, j - i + 1);
            j++;
        }

        return len;
    }
};

int main(int argc, char const *argv[])
{

    SolutionOptimized sol;
    auto ans = sol.lengthOfLongestSubstring("bbbbb");
    cout << ans << endl;

    return 0;
}