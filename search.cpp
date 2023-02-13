#include <iostream>
using namespace std;
class Node
{
public:
    int key;
    int data;
    Node *next;
    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};
class SinglyLinkedList
{
public:
    Node *head;
    SinglyLinkedList()
    {
        head = NULL;
    }
    SinglyLinkedList(Node *n)
    {
        head = n;
    }
    // search key in node
    Node *nodeExist(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }
    // append node
    void append(Node *n)
    {
        if (nodeExist(n->key) != NULL)
        {
            cout << n->key << "there is already exist . " << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "node append" << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout << "node append" << endl;
            }
        }
    }
    // prepend node
    void prepend(Node *n)
    {
        if (nodeExist(n->key) != NULL)
        {
            cout << n->key << "there is already exist . " << endl;
        }
        else
        {
            n->next = head;
            head = n;
            cout << "node prepend" << endl;
        }
    }
};
int main()
{
}