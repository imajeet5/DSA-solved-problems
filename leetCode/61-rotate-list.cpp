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
    ListNode *rotateRight(ListNode *head, int k)
    {

        if (head == NULL)
        {
            return head;
        }
        int len = 0;
        ListNode *start = head;
        while (head->next != NULL)
        {
            head = head->next;
            len++;
        }
        k = k % (len + 1);
        head->next = start;
        int m = len - k;
        for (int i = 1; i <= m; i++)
        {
            start = start->next;
        }
        ListNode *newHead = start->next;
        start->next = NULL;
        return newHead;
    }
};