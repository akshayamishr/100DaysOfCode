#include <iostream>
using namespace std;
class Stack
{
public:
    // let's assume max size of stack is 6
    int arr[6];
    int idx;
    Stack() : idx(-1) {}
    void push(int val)
    {
        if (idx == 6)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        idx++;
        arr[idx] = val;
    }
    void pop()
    {
        if (idx == -1)
        {
            cout << "Stack Underflow" << endl;
        }
        idx--;
    }
    void display()
    {
        for (int i = 0; i <= idx; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int top()
    {
        if (idx == -1)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[idx];
    }
    int size()
    {
        return idx + 1;
    }
};
int main()
{
    Stack st;
    st.push(5);
    st.push(7);
    st.push(9);
    st.push(11);
    cout << st.size() << endl;
    st.pop();
    cout << st.top() << endl;
    st.display();
}