// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
   static bool comparator(pair<int, int> m1, pair<int, int> m2)
    {
        // we have to sort in the ascending order
        if (m1.second < m2.second)
            return true;
        else if (m1.second > m2.second)
            return false;
        return false;
    }

    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        if (n == 0)
        {
            return 0;
        }

        vector<pair<int, int>> meetings;
        for (int i = 0; i < n; i++)
        {
            meetings.push_back({start[i], end[i]});
        }

        sort(meetings.begin(), meetings.end(), comparator);

        int totalMeetings = 1;
        auto currentMeeting = meetings[0];
        for (int i = 1; i < n; i++)
        {
            auto nextMeeting = meetings[i];

            if (currentMeeting.second < nextMeeting.first)
            {
                totalMeetings++;
                currentMeeting = nextMeeting;
            }
        }

        return totalMeetings;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
} // } Driver Code Ends