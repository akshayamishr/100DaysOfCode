#include <iostream>
#include <climits>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val) : left(NULL), right(NULL), val(val) {}
};

void display(Node *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    display(root->left);
    display(root->right);
}

int sum(Node *root)
{
    if (root == NULL)
        return 0;
    return (root->val + sum(root->left) + sum(root->right));
}

int size(Node *root)
{
    if (root == NULL)
        return 0;
    return (1 + size(root->left) + size(root->right));
}

int max_val(Node *root)
{
    if (root == NULL)
        return INT_MIN;
    // max(a,b,c) = max(a,max(b,c))
    return max(root->val, max(max_val(root->left), max_val(root->right)));
}

int min_val(Node *root)
{
    return root ? min(root->val, min(min_val(root->left), min_val(root->right))) : INT_MAX;
}

int product(Node *root)
{
    if (root == NULL)
        return 1;
    return (root->val * product(root->left) * product(root->right));
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

    display(a);
    cout << endl;
    cout << "Sum : " << sum(a) << endl;
    cout << "Size : " << size(a) << endl; // Number of nodes in tree
    cout << "Max_val : " << max_val(a) << endl;
    cout << "Min_val : " << min_val(a) << endl;
    cout << "Product : " << product(a) << endl;
    cout << "Level : " << level(a) << endl;
}
