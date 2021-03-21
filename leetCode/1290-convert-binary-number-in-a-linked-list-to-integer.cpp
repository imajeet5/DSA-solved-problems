

#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        vector<int> values;
        int ans = 0;
        ListNode *curr = head;
        while (curr)
        {
            values.push_back(curr->val);
            curr = curr->next;
        }
        int j = 0;
        for (int i = 0; i < values.size(); i++)
        {
            ans += values[i] + pow(2, i);
        }

        return ans;
    }
};