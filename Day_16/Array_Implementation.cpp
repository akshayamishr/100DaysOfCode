#include <iostream>
#include <vector>
using namespace std;
class Queue
{
public:
    int f, r;
    vector<int> arr;
    Queue(int val)
    {
        r = 0;
        f = 0;
        vector<int> v(val);
        arr = v;
    }

    int size()
    {
        return (r - f);
    }
    
    void push(int val)
    {
        if (r == arr.size())
        {
            cout << "Queue is full " << endl;
            return;
        }
        arr[r] = val;
        r++;
    }
    
    void pop()
    {
        if (size() == 0)
        {
            cout << "Queue is empty " << endl;
        }
        f++;
    }
    
    int front()
    {
        if (size() == 0)
        {
            cout << "Queue is empty " << endl;
        }
        return arr[f];
    }
    
    int back()
    {
        if (size() == 0)
        {
            cout << "Queue is empty " << endl;
        }
        return arr[r - 1];
    }
    
    bool empty()
    {
        return size() == 0;
    }
    
    void display()
    {
        if (size() == 0)
        {
            cout << "Queue is empty " << endl;
        }
        for (int i = f; i < r; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Queue q(10); // 10 is the max size of the queue
    q.push(1);
    q.push(2);
    q.push(3);
    q.display();
    cout << "Top element is : " << q.front() << endl;
    cout << "Size of queue : " << q.size() << endl;
    cout << "Back element is : " << q.back() << endl;
    q.pop();
    q.pop();
    q.pop();
    cout << "Size of queue after popping : " << q.size() << endl;
    q.display();
    cout << q.empty() << endl;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.display();
    cout << "Size of queue : " << q.size() << endl;
}