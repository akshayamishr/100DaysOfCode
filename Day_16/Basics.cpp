#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void display(queue<int> &q)
{
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
        int temp = q.front();
        cout << temp << " ";
        q.pop();
        q.push(temp);
    }
    cout << endl;
}

void reverse(queue<int> &q)
{
    // reversing using stack
    stack<int> st;
    // copying the queue into the stack
    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    // refilling the empty queue
    while (!st.empty())
    {
        cout << st.top() << " ";
        q.push(st.top());
        st.pop();
    }
    cout << endl;
}

void even_remove(queue<int> &q)
{
    int i = q.size() - 1;  // for indexing
    while (i >= 0)
    {
        if (i % 2 != 0)
        {
            int temp = q.front();
            q.push(temp);
            cout << temp << " ";
        }
        q.pop();
        i--;
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    display(q);
    reverse(q);
    even_remove(q); // removing elements at even indices
}