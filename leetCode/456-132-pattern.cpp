#include <bits/stdc++.h>

using namespace std;

class SolutionBrute
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (nums[k] > nums[i] && nums[k] < nums[j])
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

class SolutionStackNotWorking
{
public:
    bool find132pattern(vector<int> &nums)
    {
        stack<int> stk;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (stk.size() == 0)
            {
                stk.push(nums[i]);
            }
            else if (stk.size() == 1)
            {
                if (stk.top() < nums[i])
                {
                    stk.push(nums[i]);
                }
                else
                {
                    // we will remove the top element and start from the current element
                    stk.pop();
                    stk.push(nums[i]);
                }
            }
            else if (stk.size() == 2)
            {
                if (stk.top() > nums[i])
                {
                    // then 1 3 2 pattern exist
                    return true;
                }
                else
                {
                    // remove the first two element and start again
                    stk.pop();
                    stk.pop();
                    stk.push(nums[i]);
                }
            }
        }
        return false;
    }
};

class SolutionBruteBetter
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int n = nums.size();
        int min_i = INT_MAX;
        // instead of looping over i, we will store the min value till now
        // jth value is the current values and we will traverse again to find the kth value
        // which is greater than the min_i and less than nums[j]
        for (int j = 0; j < n; j++)
        {
            min_i = min(nums[j], min_i);
            for (int k = j + 1; k < n; k++)
            {
                if (nums[k] > min_i and nums[k] < nums[j])
                {
                    return true;
                }
            }
        }

        return false;
    }
};

class SolutionUsingStack
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
        {
            return false;
        }
        stack<int> stk;
        vector<int> min_array(nums.size());
        min_array[0] = nums[0];
        // first create min array
        for (int i = 1; i < n; i++)
        {
            min_array[i] = min(min_array[i - 1], nums[i]);
        }

        for (int j = n - 1; j > 0; j--)
        {
            if (nums[j] <= min_array[j])
                continue;
            // if the stack top most element is less than the minimum element we will keep on pop
            // this will ensure only the element that are greater than the min element will be in the stack
            while (!stk.empty() && stk.top() <= min_array[j])
            {
                stk.pop();
            }
            if (!stk.empty() && stk.top() < nums[j])
            {
                // we have found out k element, which is greater than mins[i] and less than nums[i]
                return true;
            }
            else
            {
                // if nums[j] < stk.top(), this will ensure that stack is always sorted
                stk.push(nums[j]);
            }
        }
        return false;
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