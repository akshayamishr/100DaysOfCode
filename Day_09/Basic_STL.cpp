#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> st;
    st.push(5);
    st.push(7);
    st.push(9);
    // cout << st.size() << endl;  // 3
    // st.pop();  // removes top element
    // cout << st.top() << endl; // returns topmost element
    st.push(11);
    st.push(13);
    st.push(15);
    // printing in reverse order
    stack<int> temp;
    while (st.size())
    {
        cout << st.top() << " ";
        temp.push(st.top());
        st.pop();
    }
    cout << endl;
    // refilling st stack
    while (temp.size())
    {
        cout << temp.top() << " ";
        st.push(temp.top());
        temp.pop();
    }
}