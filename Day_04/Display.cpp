#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int n) : val(n), next(NULL) {}
};

void display(Node *head)
{
    cout << head->val << " ";
    if (head->next == NULL)
        return;
    display(head->next);
}

int main()
{
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(124);
    Node *d = new Node(865);
    a->next = b;
    b->next = c;
    c->next = d;
    display(a);
}