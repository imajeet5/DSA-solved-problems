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
        next = NULL;
    }
};

int main(int argc, char const *argv[])
{
    // statically
    Node n1(1);
    Node n2(2);
    n1.next = &n2;
    Node *head = &n1;

    cout << head->data << endl;
    // cout << n1.data << " " << n2.data << endl;

    // Dynamically
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    n3->next = n4;
    return 0;
}