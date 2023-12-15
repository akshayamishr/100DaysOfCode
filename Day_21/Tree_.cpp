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

void level_order_queue(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    cout << endl;
}

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

int main()
{
    int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, INT_MIN, INT_MIN, 7, 8, 9, INT_MIN};  // INT_MIN for null node
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = tree_constructor(arr, n);
    level_order_queue(root);
}