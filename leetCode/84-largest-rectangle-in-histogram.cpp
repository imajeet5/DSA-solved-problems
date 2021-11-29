#include <bits/stdc++.h>

using namespace std;

// This is TLE solution
class Solution1
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int maxArea = 0;
        // we will loop over each hight and get the width
        for (int i = 0; i < heights.size(); i++)
        {
            // get the left index
            int left = i, right = i;
            while (left > 0 && heights[left - 1] >= heights[i])
                left--;

            while (right < (heights.size() - 1) && heights[right + 1] >= heights[i])
                right++;

            int width = right - left + 1;

            int area = heights[i] * width;
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }
};

// optimized
class Solution2
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> s;
        int leftSmall[n], rightSmall[n];

        // we will get the left small first
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
                s.pop();

            if (s.empty())
                leftSmall[i] = 0;
            else
                leftSmall[i] = s.top() + 1;

            s.push(i);
        }

        // empty the stack for reuse
        while (!s.empty())
            s.pop();

        // fill the right stack
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
                s.pop();

            if (s.empty())
                rightSmall[i] = n - 1;
            else
                rightSmall[i] = s.top() - 1;

            s.push(i);
        }

        int maxA = 0;
        for (int i = 0; i < n; i++)
        {
            maxA = max(maxA, heights[i] * (rightSmall[i] - leftSmall[i] + 1));
        }

        return maxA;
    }
};

// using single pass only
class Solution3
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        // this will store the element index increasing order
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
            {
                // then i is the index of next smaller element to the right for stack top element
                int h = heights[st.top()];
                // we will remove the current element from the stack as we are determining the height
                // and width for this element
                st.pop();
                // now we have to find the width
                int width;
                if (st.empty())
                {
                    // then width will be the right most element
                    width = i;
                }
                else
                {
                    // now current st.top() is the next smaller element to the left
                    width = i - st.top() - 1;
                    maxArea = max(maxArea, (width * h));
                }
                st.push(i);
            }
        }
        return maxArea;
    }
};