#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
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
        cout << "Memory is free from the value of " << value << endl;
    }
};
void insert(Node *&tail, int element, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }
    else
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
// deletation
void deleted(Node *&tail, int value)
{
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;
        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if (curr == prev)
        {
            tail = NULL;
        }

        if (tail == curr)
        {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}
bool isCirculer(Node *&tail)
{
    if (tail == NULL)
    {
        return true;
    }
    Node *temp = tail->next;
    while (temp != NULL && temp != tail)
    {
        temp = temp->next;
    }
    if (temp == tail)
    {
        return true;
    }
    return false;
}
void print(Node *&tail)
{

    Node *temp = tail;
    if (tail == NULL)
    {
        cout << "Empty node" << endl;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << endl;
}
int main()
{
    Node *tail = NULL;
    insert(tail, 0, 1);
    print(tail);
    insert(tail, 1, 3);
    print(tail);
    // insert(tail, 1, 3);
    // print(tail);
    // insert(tail, 1, 2);
    // print(tail);
    // insert(tail, 3, 4);
    // print(tail);
    // deleted(tail, 1);
    // print(tail);
    if (isCirculer(tail))
    {
        cout << "citrculer" << endl;
    }
    else
    {
        cout << "not circular " << endl;
    }
}