#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int ele)
    {
        this->data = ele;
        this->next = NULL;
    }
};

void printLinkedList(Node *head)
{

    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }

    cout << "NULL" << endl;
}

Node *takeInputHead()
{
    Node *head = NULL;
    Node *tail = NULL;

    int data;
    cin >> data;
    while (data != -1)
    {
        Node *n = new Node(data);
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

Node *takeInputTail()
{
    Node *head = NULL;
    Node *tail = NULL;

    int data;
    cin >> data;

    while (data != -1)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = tail->next;
        }

        cin >> data;
    }

    return head;
}

int lengthOfLinkedList(Node *head)
{
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }
    return length;
}

void printithNode(Node *head, int i)
{
    if (i < 0)
    {
        cout << "Node does not exist" << endl;
        return;
    }
    int count = 0;
    while (count < i && head != NULL)
    {
        head = head->next;
        count++;
    }
    if (head)
    {
        cout << "Element at " << i << "th position is " << head->data << endl;
    }
    else
    {
        cout << "Node does not exist" << endl;
    }
}

Node *insertAtIthPosition(Node *head, int data, int pos)
{
    if (pos < 0)
    {
        cout << "Out of range" << endl;
        return head;
    }

    Node *newNode = new Node(data);
    // insert node at head
    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node *thead = head;

    while ((pos - 1) && thead)
    {
        thead = thead->next;
        pos--;
    }

    // Now either traversalHead is null or pos == 0
    if (thead == NULL)
    {
        cout << "Out of range" << endl;
        delete newNode;
        return head;
    }
    newNode->next = thead->next;
    thead->next = newNode;
    return head;
}

Node *deleteithPosition(Node *head, int pos)
{
    if (pos < 0)
    {
        cout << "Out of range" << endl;
        return head;
    }

    if (pos == 0)
    {
        Node *nextNode = head->next;
        head->next = NULL;
        delete head;
        return nextNode;
    }

    Node *thead = head;
    while ((pos - 1) && thead)
    {
        thead = thead->next;
        pos--;
    }
    if (thead == NULL)
    {
        cout << "Out of range" << endl;
        return head;
    }
    if (thead->next == NULL)
    {
        thead == NULL;
        delete thead;
        return head;
    }
    Node *removedNode = thead->next;
    thead->next = thead->next->next;
    removedNode->next = NULL;
    delete removedNode;
    return head;
}

bool isPresent(Node *head, int element)
{
    while (head)
    {
        if (head->data == element)
        {
            return true;
        }
        head = head->next;
    }
    return false;
}

int middleElement(Node *head)
{
    if (head->next == NULL)
    {
        return head->data;
    }

    Node *slow = head;
    Node *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast)
    {
        return slow->next->data;
    }
    return slow->data;
}

Node *reverseLinkedList(Node *head)
{
    Node *currentNode = head;
    Node *previousNode = NULL;

    while (currentNode)
    {
        Node *nextNode = currentNode->next;
        currentNode->next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
    }

    return previousNode;
}

Node *mergeSortedLists(Node *list1, Node *list2)
{
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }

    // Create finalHead and finalTail for the merged linked list
    Node *finalHead = NULL;
    Node *finalTail = NULL;

    if (list1->data < list2->data)
    {
        finalHead = list1;
        list1 = list1->next;
    }
    else
    {
        finalHead = list2;
        list2 = list2->next;
    }

    finalTail = finalHead;

    while (list1 && list2)
    {
        if (list1->data < list2->data)
        {
            finalTail->next = list1;
            list1 = list1->next;
        }
        else
        {
            finalTail->next = list2;
            list2 = list2->next;
        }
        finalTail = finalTail->next;
    }
    if (list1)
    {
        finalTail->next = list1;
    }
    else
    {
        finalTail->next = list2;
    }

    return finalHead;
}

Node *mergeSortedListUsingRecursion(Node *list1, Node *list2)
{
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }
    Node *firstHead = NULL;
    if (list1->data < list2->data)
    {
        firstHead = list1;
        firstHead->next = mergeSortedLists(list1->next, list2);
    }
    else
    {
        firstHead = list2;
        firstHead->next = mergeSortedLists(list1, list2->next);
    }
    return firstHead;
}

Node *sortList(Node *head)
{
    // if list is empty or list have only one element. List is already sorted
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // second half
    Node *list2 = slow->next;
    // break the connection of the first half with rest of the list
    slow->next = NULL;

    // sort each half
    head = sortList(head);
    list2 = sortList(list2);

    // merging the sorted list
    head = mergeSortedListUsingRecursion(head, list2);
    return head;
}

int main(int argc, char const *argv[])
{

    Node *head = new Node(10);
    Node *tail = head;
    cout << tail << endl;
    cout << head << endl;

    for (int i = 2; i < 10; i++)
    {
        tail->next = new Node(i * 10);
        tail = tail->next;
    }

    printLinkedList(head);
    printLinkedList(head);

    Node *userLL1 = takeInputTail();

    userLL1 = sortList(userLL1);

    printLinkedList(userLL1);

    int element, pos;

    // cout << "Enter element and position to insert " << endl;
    // cin >> element >> pos;

    // userLL1 = insertAtIthPosition(userLL1, element, pos);

    // cout << "Enter position to delete " << endl;

    // cin >> pos;

    // userLL1 = deleteithPosition(userLL1, pos);

    // cout << "length of list " << lengthOfLinkedList(userLL1) << endl;

    // for (size_t i = 0; i < lengthOfLinkedList(userLL1); i++)
    // {
    //     printithNode(userLL1, i);
    // }

    // cout << "Middle element of the node is " << middleElement(userLL1) << endl;

    // Node *reversedList = reverseLinkedList(userLL1);

    // cout << "Reversed List" << endl;
    // printLinkedList(reversedList);

    Node *userLL2 = takeInputHead();
    // Node *userLL2 = takeInputTail();
    printLinkedList(userLL2);
    userLL2 = sortList(userLL2);

    printLinkedList(userLL2);

    // cout << "Enter element and position to insert " << endl;
    // cin >> element >> pos;

    // userLL2 = insertAtIthPosition(userLL2, element, pos);

    // cout << "length of list " << lengthOfLinkedList(userLL2) << endl;

    // for (size_t i = 0; i < lengthOfLinkedList(userLL2); i++)
    // {
    //     printithNode(userLL2, i);
    // }

    // cout << "Middle element of the node is " << middleElement(userLL2) << endl;

    Node *mergedList = mergeSortedListUsingRecursion(userLL1, userLL2);

    printLinkedList(mergedList);

    return 0;
}