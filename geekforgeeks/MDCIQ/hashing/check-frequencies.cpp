// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function template for C++
class Solution
{
public:
    int getIdx(char ch)
    {
        return (ch - 'a');
    }

    bool areFreqEqual(vector<int> freq, char c)
    {
        int n = freq.size();
        for (int i = 0; i < n; i++)
        {
            if (freq[i] > 0 && freq[i] != freq[getIdx(c)])
                return false;
        }
        return true;
    }

    bool sameFreq(string s)
    {
        const int MAX_CHAR = 26;
        int n = s.length();

        if (n == 0)
            return true;

        vector<int> freq(MAX_CHAR, 0);
        // store the frequency count of all the characters present in the string
        for (int i = 0; i < n; i++)
            freq[getIdx(s[i])]++;

        if (areFreqEqual(freq, s[0]))
            return true;
        // try decreasing frequency of all the characters present in the string
        // if frequency becomes equal then return true otherwise restore the frequency
        for (int i = 0; i < n; i++)
        {
            freq[getIdx(s[i])]--;
            if (areFreqEqual(freq, s[0]))
                return true;
            freq[getIdx(s[i])]++;
        }

        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.sameFreq(s) << endl;
    }
}

// } Driver Code Ends