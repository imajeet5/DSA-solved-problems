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
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }

        // for reversing the list we will keep two pointer
        // one is to track the previous element and other is for next element
        ListNode *prev = NULL;
        while (head != NULL)
        {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode *head)
    {
        if (head == NULL)
        {
            return true;
        }

        ListNode *fast = head, *slow = head;

        // first we will get the middle of the list
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // for the case of odd length list fast will not be NULL
        // so we will make slow part the smaller
        if (fast != NULL)
        {
            slow = slow->next;
        }

        // after this we will reverse the list from the slow part
        slow = reverseList(slow);
        fast = head;

        // we will add condition to the slow pointer bcz it is sorter in length and
        // also handle the case of odd length
        while (slow != NULL)
        {
            if (fast->val != slow->val)
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};