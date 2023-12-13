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

void level_order(Node *root, int count, int level)
{
    if (root == NULL)
        return;
    count++; // count++ is level of root
    if (count == level)
    {
        cout << root->val << " ";
        count--;
        return;
    }
    level_order(root->left, count, level);
    level_order(root->right, count, level);
}

int level(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(level(root->left), level(root->right));
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

    int max_level = level(a);
    for (int i = 1; i <= max_level; i++)
    {
        level_order(a, 0, i);
        cout << endl;
    }
}