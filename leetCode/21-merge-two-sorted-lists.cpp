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

class SolutionUsingNewList
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *merged = new ListNode();

        ListNode *head = merged;

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                merged->next = new ListNode(l1->val);
                merged = merged->next;
                l1 = l1->next;
            }
            else
            {
                merged->next = new ListNode(l2->val);
                merged = merged->next;
                l2 = l2->next;
            }
        }

        while (l1)
        {
            merged->next = new ListNode(l1->val);
            merged = merged->next;
            l1 = l1->next;
        }

        while (l2)
        {
            merged->next = new ListNode(l2->val);
            merged = merged->next;
            l2 = l2->next;
        }

        return head->next;
    }
};

class SolutionWithoutUsingNewList
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {

        /** 
         * First we store the lowest value node in l1
         * then we move l1 forward until it is less then l2 value 
         * and store the previous value in temp
         */

        if (l1 == NULL)
        {
            return l2;
        }

        if (l2 == NULL)
        {
            return l1;
        }

        if (l1->val > l2->val)
        {
            // this means l2 is smaller, so we will change l1 to l2
            swap(l1, l2);
        }
        ListNode *result = l1;
        while (l1 && l2)
        {
            ListNode *temp = NULL;
            while (l1 && l1->val < l2->val)
            {
                temp = l1;
                l1 = l1->next;
            }
            // when this is over, we will assign temp to l2 as it is the next smaller element
            temp->next = l2;
            swap(l1, l2);
        }

        return result;
    }
};