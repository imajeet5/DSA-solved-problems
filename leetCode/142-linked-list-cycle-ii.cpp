#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {

        if (head == NULL)
        {
            return head;
        }
        ListNode *slow = head, *fast = head;

        // now we will get the intersection point of the two lists
        do
        {
            if (fast == NULL || fast->next == NULL)
            {
                // then there is no cycle in the list
                return NULL;
            }

            // move slow by one
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);

        // we have got the point of intersection
        // now we will move the fast pointer
        fast = head;
        // cout<<"intersection point: " << slow->val << endl;

        // we will move them until they are not meet
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};