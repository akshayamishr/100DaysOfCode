#include <iostream>
#include <stack>
using namespace std;

void display(stack<int> &st)
{
    stack<int> temp;
    while (st.size())
    {
        temp.push(st.top());
        st.pop();
    }
    // refilling st stack
    while (temp.size())
    {
        cout << temp.top() << " ";
        st.push(temp.top());
        temp.pop();
    }
    cout << endl;
}

void display_rev_rec(stack<int> &st)
{
    if (st.size() == 0)
        return;
    int n = st.top();
    cout << n << " ";
    st.pop();
    display_rev_rec(st);
    st.push(n);
}

void display_rec(stack<int> &st)
{
    if (st.size() == 0)
        return;
    int n = st.top();
    st.pop();
    display_rec(st);
    cout << n << " ";
    st.push(n);
}

void push_at_bottom_rec(stack<int> &st, int n)
{

    if (st.size() == 0)
    {
        st.push(n);
        return;
    }
    int x = st.top();
    st.pop();
    push_at_bottom_rec(st, n);
    st.push(x);
}

void push_at_bottom(stack<int> &st, int n)
{
    stack<int> temp;
    while (st.size())
    {
        temp.push(st.top());
        st.pop();
    }
    st.push(n);
    while (temp.size())
    {
        st.push(temp.top());
        temp.pop();
    }
}

void push_at_idx(stack<int> &st, int idx, int n)
{
    stack<int> temp;
    while (st.size() > idx)
    {
        temp.push(st.top());
        st.pop();
    }
    st.push(n);
    while (temp.size())
    {
        st.push(temp.top());
        temp.pop();
    }
}

void reverse_rec(stack<int> &st)
{
    if (st.size() == 1)
        return;
    int n = st.top();
    st.pop();
    reverse_rec(st);
    push_at_bottom(st, n);
}

int main()
{
    stack<int> st;
    st.push(5);
    st.push(7);
    st.push(9);
    st.push(11);
    st.push(13);
    st.push(15);
    display(st);
    push_at_bottom(st, 3);
    display(st);

    push_at_idx(st, 3, 0);
    display_rec(st);
    cout << endl;

    display_rev_rec(st);
    push_at_bottom_rec(st, 1);
    cout << endl;
    display(st);
    
    reverse_rec(st);
    display(st);
}