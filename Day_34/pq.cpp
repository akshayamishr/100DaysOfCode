#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    vector<int> v = {203, 123, 270, 780, 500};

    // max heap
    priority_queue<int, vector<int>, less<int>> mp(v.begin(), v.end());

    priority_queue<int> temp1 = mp;
    cout << "Max Heap : " << endl;
    while (!temp1.empty())
    {
        cout << temp1.top() << " ";
        temp1.pop();
    }
    cout << endl;

    // min heap
    priority_queue<int, vector<int>, greater<int>> minq(v.begin(), v.end());
    cout << "Min Heap : " << endl;
    priority_queue<int, vector<int>, greater<int>> temp2 = minq;
    while (!temp2.empty())
    {
        cout << temp2.top() << " ";
        temp2.pop();
    }
    cout << endl;
}