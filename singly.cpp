#include <iostream>
#include <map>
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
        int val = data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Free of memory value is " << val << endl;
    }
};
void insertNodeHade(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertNodeTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void insertPosition(Node *&tail, Node *&head, int position, int d)
{
    if (position == 1)
    {
        insertNodeHade(head, d);
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
        insertNodeTail(tail, d);
        return;
    }

    Node *insertNode = new Node(d);
    insertNode->next = temp->next;
    temp->next = insertNode;
}
// loop ha ki na

Node *isLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *f = head;
    Node *s = head;
    while (f != NULL && s != NULL)
    {
        f = f->next;
        if (f != NULL)
        {
            f = f->next;
        }
        s = s->next;
        if (f == s)
        {
            return f;
        }
    }
    return NULL;
}

// starting loop
Node *getStartingLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *interLoop = isLoop(head);
    Node *againLoop = head;
    while (againLoop != interLoop)
    {
        interLoop = interLoop->next;
        againLoop = againLoop->next;
    }
    return againLoop;
}

// loop ha ki na

// bool isLoop(Node *head)
// {
//     if (head == NULL)
//     {
//         return false;
//     }
//     map<Node *, bool> visited;
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         if (visited[temp] == true)
//         {
//             return true;
//         }
//         visited[temp] = true;
//         temp = temp->next;
//     }
//     return false;
// }
// circular ha ki na

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

// Remove Loop
void removeLoop(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    Node *startCounting = getStartingLoop(head);
    Node *temp = startCounting;
    while (temp->next != startCounting)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}
// delete any position of node
void deleteNode(Node *&head, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
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

int main()
{
    Node *node1 = new Node(5);
    Node *head = node1;
    Node *tail = node1;
    insertNodeTail(tail, 6);
    // print(head);
    insertNodeTail(tail, 7);
    insertNodeTail(tail, 8);
    insertNodeTail(tail, 9);
    // print(head);
    // insertPosition(tail, head, 1, 8);
    // print(head);
    // deleteNode(head, 4);
    // print(head);

    tail->next = head->next->next;
    // cout << "head" << head->data << endl;
    // cout << "tail" << tail->data << endl;

    if (isLoop(head))
    {
        cout << "loop" << endl;
    }
    else
    {
        cout << "not loop " << endl;
    }

    Node *result = getStartingLoop(head);
    // cout << "Loop is start at " << result->data << endl;

    removeLoop(head);
    print(head);

    if (isLoop(head))
    {
        cout << "loop" << endl;
    }
    else
    {
        cout << "not loop " << endl;
    }
    // insertNodeHade(head, 10);
    // print(head);
    // insertNodeHade(head, 100);
    // print(head);
    // if (isCirculer(tail))
    // {
    //     cout << "this is circular " << endl;
    // }
    // else
    // {
    //     cout << "this is not circular " << endl;
    // }
}
