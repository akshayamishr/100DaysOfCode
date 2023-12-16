#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val) : left(NULL), right(NULL), val(val) {}
};

void preorder(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *temp = st.top();
        st.pop();
        cout << temp->val << " ";
        if (temp->right)
            st.push(temp->right);
        if (temp->left)
            st.push(temp->left);
    }
    cout << endl;
}

void inorder(Node *root)
{
    vector<int> v;
    stack<Node *> st;
    Node *temp = root;
    while (temp || !st.empty())
    {
        if (temp)
        {
            st.push(temp);
            temp = temp->left;
        }
        else
        {
            Node *temp2 = st.top();
            st.pop();
            v.push_back(temp2->val);
            temp = temp2->right;
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> st;
    vector<int> v;
    st.push(root);
    while (!st.empty())
    {
        Node *temp = st.top();
        st.pop();
        v.push_back(temp->val);
        if (temp->left)
            st.push(temp->left);
        if (temp->right)
            st.push(temp->right);
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
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

    cout << "Preorder : ";
    preorder(a);
    cout << "Inorder : " ;
    inorder(a);
    cout << "Postorder : ";
    postorder(a);
}