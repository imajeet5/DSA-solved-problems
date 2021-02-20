// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string UncommonChars(string A, string B)
    {
        unordered_map<char, int> mpA;
        unordered_map<char, int> mpB;
        set<char> uncom;
        for (int i = 0; i < A.size(); i++)
        {
            mpA[A[i]]++;
        }

        for (int i = 0; i < B.size(); i++)
        {
            mpB[B[i]]++;
        }
        for (int i = 0; i < A.size(); i++)
        {
            // if B does not have element that is present in A
            if (mpB[A[i]] == 0)
            {
                uncom.insert(A[i]);
            }
        }
        for (int i = 0; i < B.size(); i++)
        {
            // if A does not have element that is present in B
            if (mpA[B[i]] == 0)
            {
                uncom.insert(B[i]);
            }
        }

        string ans = "";
        for (auto ch : uncom)
        {
            ans += ch;
        }
        return ans == "" ? "-1" : ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string A, B;
        cin >> A;
        cin >> B;
        Solution ob;
        cout << ob.UncommonChars(A, B);
        cout << endl;
    }
    return 0;
} // } Driver Code Ends