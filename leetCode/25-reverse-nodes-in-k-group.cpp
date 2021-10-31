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
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        if (head == NULL || k == 1)
            return head;

        ListNode *d = new ListNode(0);
        d->next = head;

        // so we will define three pointers curr, nxt to track next node, pre to track the previous node
        ListNode *curr = d, *nxt = d, *pre = d;
        int count = 0;

        // get the total number of nodes
        while (curr->next != NULL)
        {
            curr = curr->next;
            count++;
        }

        // so we will reverse the node in set of k
        while (count >= k)
        {
            curr = pre->next;
            nxt = curr->next;
            for (int i = 1; i < k; i++)
            {
                // first the current next will point to the element one next to it
                curr->next = nxt->next;
                // element next to current will point to the element before it
                nxt->next = pre->next;
                // as the link of element next to current is broken we will store the
                // pre->next to nxt and pre will move on step forward
                pre->next = nxt;
                // now nxt will move one step forward
                nxt = curr->next;
            }
            // when one of the iteration is over, we will move pre to curr so that it can start the
            // same thing from that node
            pre = curr;
            count -= k;
        }

        return d->next;
    }
};
