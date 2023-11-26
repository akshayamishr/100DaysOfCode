#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> st;
    st.push(5);
    st.push(7);
    st.push(9);
    st.push(11);
    st.push(13);
    st.push(15);
    stack<int> temp1, temp2;
    while (st.size())
    {
        temp1.push(st.top());
        st.pop();
    }
    while (temp1.size())
    {
        temp2.push(temp1.top());
        temp1.pop();
    }
    while (temp2.size())
    {
        st.push(temp2.top());
        cout << st.top() << " ";
        temp2.pop();
    }
}