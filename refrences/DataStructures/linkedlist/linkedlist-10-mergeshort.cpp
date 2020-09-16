#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void printLL(Node *head)
{
    Node *temp_itr = head;
    while (temp_itr != NULL)
    {
        cout << temp_itr->data << "->";
        temp_itr = temp_itr->next;
    }
    cout << "NULL" << endl;
    temp_itr = head;
}

/*
Note: Scope of the statically created memeory is only for one iteration, for next iteration it will be erased. 
So we have to allocate memory dynamically. 

*/

Node *takeInput_tail()
{
    int data;
    cin >> data;
    Node *head = NULL; // LL is empty
    Node *tail = NULL;

    while (data != -1)
    {
        // static creation will not work as it is valid for iteration, so we have to use dynamic memeory allocation
        Node *n = new Node(data);
        // if 1st node
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            // current tail->next will point to new node
            tail->next = n;
            // update the current tail to new node
            tail = n;
        }

        cin >> data;
    }
    return head;
}
Node *takeInput_head()
{
    int data;
    cin >> data;
    Node *head = NULL; // LL is empty
    Node *tail = NULL;

    while (data != -1)
    {
        // static creation will not work as it is valid for iteration, so we have to use dynamic memeory allocation
        Node *n = new Node(data);
        // if 1st node
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            n->next = head;
            head = n;
        }

        cin >> data;
    }
    return head;
}

int lengthLL(Node *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }

    return count;
}

// my implementation
void printithNode(Node *head, int index)
{
    int position = 0;
    bool isNodeFound = false;
    while (head && !isNodeFound)
    {

        if (position == index)
        {
            cout << "Element at " << index << " is " << head->data << endl;
            isNodeFound = true;
        }
        position++;
        head = head->next;
    }
    if (!isNodeFound)
    {
        cout << "Node does not exist" << endl;
    }
}

// course implementation
void printIthNode2(Node *head, int i)
{

    if (i < 0)
    {
        cout << "Node does not exist" << endl;
        return;
    }
    int count = 1;
    while (count <= i && head != NULL)
    {

        head = head->next;
        count++;
    }
    if (head)
        cout << "Element at " << i << " is " << head->data << endl;
    else
        cout << "Node does not exist" << endl;
}

Node *mergeTwoList_mine(Node *list1, Node *list2)
{
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }
    Node *fh = NULL;
    if (list1->data < list2->data)
    {
        fh = list1;
        list1 = list1->next;
    }
    else
    {
        fh = list2;
        list2 = list2->next;
    }
    Node *ft = fh;
    while (list1 && list2)
    {
        if (list1->data < list2->data)
        {
            ft->next = list1;
            list1 = list1->next;
        }
        else
        {
            ft->next = list2;
            list2 = list2->next;
        }
        ft = ft->next;
    }
    if (list1)
    {
        ft->next = list1;
    }
    else
    {
        ft->next = list2;
    }
    return fh;
}

Node *mergeTwoListRecursion(Node *list1, Node *list2)
{
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }
    Node *fh = NULL;
    if (list1->data < list2->data)
    {
        fh = list1;

        fh->next = mergeTwoListRecursion(list1->next, list2);
    }
    else
    {
        fh = list2;
        fh->next = mergeTwoListRecursion(list1, list2->next);
    }
    return fh;
}

Node *sortList(Node *head)
{
    //1. base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    //2. break the list into two halves
    Node *slow = head;
    Node *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    };
    // second link list
    Node *secondHalf = slow->next;
    // this will break the connection of the head with the rest of the list
    slow->next = NULL;
    //3. sort each half
    head = sortList(head);
    secondHalf = sortList(secondHalf);
    //4. merge sorted halves
    head = mergeTwoListRecursion(head, secondHalf);
    return head;
}

int main(int argc, char const *argv[])
{
    Node *head1 = takeInput_tail();
    head1 = sortList(head1);

    printLL(head1);

    return 0;
}
