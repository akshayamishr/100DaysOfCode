#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int n) : val(n), next(NULL) {}
};
int main()
{
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(124);
    Node* d = new Node(865);
    a->next = b;
    b->next = c;
    c->next = d;
    Node* temp = a;
    while(temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}