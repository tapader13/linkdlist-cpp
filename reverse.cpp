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
};
Node *reverse(Node *&head, int d)
{
    if (head == NULL || head->next == NULL)
    {
        return head;

        // Node *temp = new Node(d);
        // head = temp;
    }

    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
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
int main()
{
    Node *head = NULL;
    reverse(head, 3);
    print(head);
    reverse(head, 4);
    print(head);
    reverse(head, 5);
    print(head);
}