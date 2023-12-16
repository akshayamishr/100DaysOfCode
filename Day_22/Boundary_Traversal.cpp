#include <iostream>
#include <queue>
#include <climits>
#include <string>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val) : left(NULL), right(NULL), val(val) {}
};

Node *tree_constructor(int arr[], int n)
{
    queue<Node *> q;
    Node *root = new Node(arr[0]);
    q.push(root);
    int i = 1, j = 2;
    while (!q.empty() && i < n)
    {
        Node *temp = q.front();
        Node *l; // left node of q.front
        Node *r; // right node of q.fornt
        q.pop();
        if (arr[i] != INT_MIN)
        {
            l = new Node(arr[i]);
            q.push(l);
        }
        else
            l = NULL;
        temp->left = l;

        if (j != n && arr[j] != INT_MIN)
        {
            r = new Node(arr[j]);
            q.push(r);
        }
        else
            r = NULL;
        temp->right = r;

        i += 2;
        j += 2;
    }
    return root;
}

void left_boundary(Node *root)
{
    if (root == NULL)
        return;
    if (!root->left && !root->right)
        return;
    cout << root->val << " ";
    left_boundary(root->left);
    if (root->left == NULL)
        left_boundary(root->right);
}

void bottom_boundary(Node *root)
{
    if (root == NULL)
        return;
    if (!root->left && !root->right)
    {
        cout << root->val << " ";
        return;
    }
    bottom_boundary(root->left);
    bottom_boundary(root->right);
}

void right_boundary(Node *root)
{
    if (root == NULL)
        return;
    if (!root->left && !root->right)
        return;
    right_boundary(root->right);
    if (root->right == NULL)
        right_boundary(root->left);
    cout << root->val << " ";
}

void boundary(Node *root)
{
    if (root)
    {
        left_boundary(root);
        bottom_boundary(root);
        right_boundary(root->right);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, 7, INT_MIN, 8, INT_MIN, 9, 10, INT_MIN, 11, INT_MIN, 12, INT_MIN, 13, INT_MIN, 14, 15, 16, INT_MIN, 17, INT_MIN, INT_MIN, 18, INT_MIN, 19, INT_MIN, INT_MIN, INT_MIN, 20, 21, 22, 23, INT_MIN, 24, 25, 26, 27, INT_MIN, INT_MIN, 28, INT_MIN, INT_MIN};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = tree_constructor(arr, n);
    boundary(root);
}