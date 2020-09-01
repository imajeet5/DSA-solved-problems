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
        cout << temp_itr->data << " ";
        temp_itr = temp_itr->next;
    }
    cout << endl;
    temp_itr = head;
    // while (temp_itr != NULL)
    // {
    //     cout << temp_itr->data << " ";
    //     temp_itr = temp_itr->next;
    // }
    // cout << endl;
}

int main(int argc, char const *argv[])
{
    // statically
    Node n1(1);
    Node *head = &n1;
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    
    // Dynamically
    

    printLL(head);

    return 0;
}