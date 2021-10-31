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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        unordered_map<ListNode *, bool> mpElemA;
        unordered_map<ListNode *, bool> mpElemB;

        while (headA != NULL && headB != NULL)
        {
            mpElemA[headA] = true;
            mpElemB[headB] = true;
            if (mpElemB[headA] || mpElemA[headB])
            {
                return mpElemB[headA] ? headA : headB;
            }
            headA = headA->next;
            headB = headB->next;
        }

        while (headA != NULL)
        {
            if (mpElemB[headA])
            {
                return headA;
            }

            headA = headA->next;
        }

        while (headB != NULL)
        {
            if (mpElemA[headB])
            {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};

class Solution2
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
            return NULL;

        ListNode *d1 = headA, *d2 = headB;

        while (d1 != d2)
        {
            d1 = d1 == NULL ? headA : d1->next;
            d2 = d2 == NULL ? headB : d2->next;
        }

        return d1;
    }
};