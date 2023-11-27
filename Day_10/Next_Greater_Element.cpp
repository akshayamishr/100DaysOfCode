#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    stack<int> st;
    st.push(arr[n - 1]);
    int ans[n];
    ans[n - 1] = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        while (st.size() && st.top() <= arr[i])
            // this loop leaves stack with next greater element for n-2 element
            st.pop();
        // marking ans in the ans element
        if (st.size())
            ans[i] = st.top();
        else
            ans[i] = -1;
        // pushing the arr[i] into stack
        st.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}