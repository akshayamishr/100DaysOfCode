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
    st.push(0);
    int ans[n];
    ans[0] = 1;
    for (int i = 1; i < n; i++)
    {
        while (st.size() && arr[st.top()] <= arr[i])
            st.pop();
        if (st.size())
            ans[i] = st.top();
        else
            ans[i] = -1;
        st.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        ans[i] = i - ans[i];
        cout << ans[i] << " ";
    }
    cout << endl;
}