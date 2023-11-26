#include <iostream>
using namespace std;
class Node
{
public:
    Node *next;
    int val;
    Node(int n) : next(NULL), val(n) {}
};
class Stack
{
    public:
    Node *head;
    int size;
    Stack() : head(NULL), size(0) {}

    void push(int n)
    {
        Node *a = new Node(n);
        a->next = head;
        head = a;
        size++;
    }
    
    void pop()
    {
        if (size == 0)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        head = head->next;
        size--;
    }
    
    int top()
    {
        if (size == 0)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return (head->val);
    }
    
    void dis(Node *temp)
    {
        if (temp == NULL)
            return;
        dis(temp->next);
        cout << temp->val << " ";
    }
    
    void display()
    {
        Node *temp = head;
        dis(temp);
        cout << endl;
    }
};
int main()
{
    Stack st;
    st.push(5);
    st.push(7);
    st.push(9);
    st.push(11);
    cout << st.size << endl;
    st.pop();
    cout << st.top() << endl;
    st.display();
}