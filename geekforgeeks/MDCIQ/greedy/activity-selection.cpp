// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    struct Activities
    {
        int start, finish;
    };

    static bool activityCompare(Activities s1, Activities s2)
    {
        return (s1.finish < s2.finish);
    }

    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        Activities act[n];
        for (int i = 0; i < n; i++)
        {
            act[i].start = start[i];
            act[i].finish = end[i];
        }

        sort(act, act + n, activityCompare);
        int res = 0;

        if (n == 0)
        {
            return res;
        }

        res++;
        int i = 0;
        for (int j = 0; j < n; j++)
        {
            // if next activity time is greater then the start time of the current activity then we will pick that activity
            if (act[j].start > act[i].finish)
            {
                res++;
                // update the current activity
                i = j;
            }
        }

        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;

    //testcases
    cin >> t;
    while (t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);

        //adding elements to arrays start and end
        for (int i = 0; i < n; i++)
            cin >> start[i];
        for (int i = 0; i < n; i++)
            cin >> end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
// } Driver Code Ends