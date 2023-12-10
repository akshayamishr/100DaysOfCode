#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n = 0;
    cout << "Enter the number of element in the array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            q.push(i);
    }
    int k;
    cout << "Enter the size of array : ";
    cin >> k;
    int i = 0;
    int ans[n - k + 1];
    while (i < n - k + 1)
    {
        while (q.size() && q.front() < i)
            q.pop();
        if (q.size() == 0 || q.front() >= i + k)
            ans[i] = 0;
        else
            ans[i] = arr[q.front()];
            i++;
    }
    for (int i = 0; i < n - k + 1; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}