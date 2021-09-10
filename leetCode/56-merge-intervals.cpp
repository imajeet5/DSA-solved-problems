#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool compareInterval(vector<int> first, vector<int> second)
    {
        return (first[0] < second[0]);
    };

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        int n = intervals.size();

        vector<vector<int>> ans;

        if (n == 0)
        {
            return ans;
        }

        stack<vector<int>> s;

        sort(intervals.begin(), intervals.end(), compareInterval);

        s.push(intervals[0]);

        for (int i = 1; i < n; i++)
        {
            auto top = s.top();

            // if ending of the top value is less then the current value
            // then there is no overlap
            if (top[1] < intervals[i][0])
            {
                s.push(intervals[i]);
            }
            else
            {
                top[1] = max(intervals[i][1], top[1]);
                s.pop();
                s.push(top);
            }
        }

        while (!s.empty())
        {
            ans.push_back(s.top());

            s.pop();
        }

        return ans;
    }
};