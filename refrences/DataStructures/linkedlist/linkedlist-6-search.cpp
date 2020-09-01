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

Node *insertIthPosition(Node *head, int pos, int data)
{
    if (pos < 0)
    {
        cout << "Out of range" << endl;
        return head;
    }

    Node *tempHead = head;

    Node *newElement = new Node(data);
    if (pos == 0)
    {
        newElement->next = head;
        head = newElement;
        return head;
    }

    while ((pos - 1) && tempHead)
    {
        tempHead = tempHead->next;
        pos--;
    }
    if (tempHead)
    {
        // Node *beforeElement = tempHead;
        // Node *afterElement = tempHead->next;
        // beforeElement->next = newElement;
        // newElement->next = afterElement;
        newElement->next = tempHead->next;
        tempHead->next = newElement;
    }
    else
    {
        cout << "Out of range" << endl;
        delete newElement;
    }
    return head;
}

Node *deleteIthElement(Node *head, int pos)
{
    Node *current = head;
    if (pos < 0)
    {
        return head;
    }
    if (pos == 0 && head)
    {
        Node *newHead = head->next;
        head->next = NULL;
        delete head;
        return newHead;
    }
    while ((pos - 1) && current)
    {
        current = current->next;
        pos--;
    }
    if (current && current->next)
    {
        Node *temp = current->next;
        current->next = current->next->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        cout << "Out of range" << endl;
    }
    return head;
}

bool isPresent(Node *head, int data)
{
    Node *curr = head;
    while (curr)
    {
        if (curr->data == data)
            return true;
        curr = curr->next;
    }
    return false;
};

bool isPresentRecur(Node *head, int data){
    if(!head){
        return false;
    }
    if(head->data == data){
        return true;
    }
    return isPresentRecur(head->next, data);
}

int main(int argc, char const *argv[])
{
    Node *head1 = takeInput_tail();
    int num = 1, index;

    printLL(head1);
    while(num){
         cout << "Enter number to find " << endl;
    cin >> num;
    string result = isPresentRecur(head1, num) ? "Found" : "Not Found" ;
    cout << result << endl;
    }
   

    return 0;
}
