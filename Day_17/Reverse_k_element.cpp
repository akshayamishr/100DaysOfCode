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

void reverse(queue<int> &q, int k)
{
    int n = q.size();
    stack<int> temp1;
    for (int i = 0; i < k; i++)
    {
        temp1.push(q.front());
        q.pop();
    }
    for (int i = 0; i < n; i++)
    {
        if (i < k)
        {
            q.push(temp1.top());
            temp1.pop();
        }
        else
        {
            int ele = q.front();
            q.push(ele);
            q.pop();
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements in queue : ";
    cin >> n;
    queue<int> q;
    cout << "Enter the elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        q.push(ele);
    }
    int k;
    do
    {
        cout << "Enter the value of k : ";
        cin >> k;
    } while (k > n);
    reverse(q, k);
    display(q);
}