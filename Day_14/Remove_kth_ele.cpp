#include <iostream>
#include <stack>
using namespace std;

void display(stack<int> *st)
{
    stack<int> temp;
    for (int i = 0; st->size(); i++)
    {
        temp.push(st->top());
        st->pop();
    }
    for (int i = 0; temp.size(); i++)
    {
        st->push(temp.top());
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> st;
    stack<int> temp;
    int n;
    cout << "Enter the number of numbers : ";
    cin >> n;
    cout << "Enter the elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        st.push(num);
    }
    int k;
    cout << "Enter the value of k : ";
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        temp.push(st.top());
        st.pop();
    }
    temp.pop();
    for (int i = 0; i < k - 1; i++)
    {
        st.push(temp.top());
        temp.pop();
    }
    display(&st);
}