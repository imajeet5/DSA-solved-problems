#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    };
};

class SolutionUsingExtraSpace
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *itr = head;
        unordered_map<Node *, Node *> mp;

        mp[NULL] = NULL;

        while (itr != NULL)
        {
            // create new nodes and store them in map
            mp[itr] = new Node(itr->val);
            itr = itr->next;
        }

        // Now again traverse the list and join the pointer
        itr = head;
        while (itr != NULL)
        {
            Node *currentNode = mp[itr];
            currentNode->next = mp[itr->next];
            currentNode->random = mp[itr->random];
            itr = itr->next;
        }

        return mp[head];
    }
};

class SolutionWithoutUsingExtraSpace
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *itr = head;
        //first step is to insert a new Node with the same value between the existing nodes
        while (itr != NULL)
        {
            Node *next = itr->next;
            Node *copy = new Node(itr->val);
            itr->next = copy;
            copy->next = next;
            itr = next;
        }
        // now we will start assigning the random pointers to the copied nodes
        itr = head;
        while (itr != NULL)
        {
            // if itr random exists
            if (itr->random)
            {
                itr->next->random = itr->random->next;
            }

            itr = itr->next->next;
        }

        // now we will seperat the copied node and the original list
        Node *d = new Node(0);
        Node *newListHead = d;

        itr = head;

        while (itr != NULL)
        {
            Node *next = itr->next->next;
            d->next = itr->next;
            itr->next = next;
            // move the dummy pointer by one step
            d = d->next;
            // and itr to next element
            itr = next;
        }

        return newListHead->next;
    }
};