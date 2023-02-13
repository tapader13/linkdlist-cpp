#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int d)
    {
        data = d;
        prev = NULL;
        next = NULL;
    }
    ~Node()
    {
        int value = data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "deleted value is " << value << endl;
    }
};
// insert head
void insertHead(Node *&head, Node *&tail, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
// insert tail
void insertTail(Node *&head, Node *&tail, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
// insert any position
void insertPosition(Node *&tail, Node *&head, int position, int d)
{
    if (position == 1)
    {
        insertHead(head, tail, d);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    // end e insert
    if (temp->next == NULL)
    {
        insertTail(head, tail, d);
        return;
    }

    Node *insertNode = new Node(d);
    insertNode->next = temp->next;
    temp->next->prev = insertNode;
    temp->next = insertNode;
    insertNode->prev = temp;
}
// delete any position of node
void deleteNode(Node *&head, int position)
{
    if (position == 1)
    {
        Node *temp = head;

        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int count = 1;
        while (count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// get length
// void getLength(Node *&head)
// {
//     int len = 0;
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         len++;
//         temp = temp->next;
//     }
//     cout << "Length is " << len;
// }
int main()
{
    // Node *node1 = new Node(6);
    // Node *head = node1;
    // Node *tail = node1;
    Node *head = NULL;
    Node *tail = NULL;
    print(head);
    insertHead(head, tail, 8);
    print(head);
    insertTail(head, tail, 10);
    print(head);
    insertPosition(tail, head, 3, 400);
    print(head);
    deleteNode(head, 2);
    print(head);
    // getLength(head);
}