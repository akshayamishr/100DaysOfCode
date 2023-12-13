#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val) : left(NULL), right(NULL), val(val) {}
};

void preorder(Node *root, int count, int level)
{
    if (root == NULL)
        return;
    count++;  // count++ is level of root
    if (count == level)
    {
        cout << root->val << " ";
        count--;
        return;
    }
    preorder(root->left, count, level);
    preorder(root->right, count, level);
}

int main()
{
    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);
    Node *f = new Node(6);
    Node *g = new Node(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    int level;
    cout << "Enter level : ";
    cin >> level;

    preorder(a, 0, level);
}