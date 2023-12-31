#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class heap
{
private:
    vector<int> hp;
    void upheapify(int n)
    {
        int child_idx = n ;
        int parent_idx = (child_idx - 1) / 2;
        while (child_idx > 0)
        {
            if (hp[child_idx] < hp[parent_idx])
                break;

            swap(hp[child_idx], hp[parent_idx]);
            child_idx = parent_idx;
            parent_idx = (child_idx - 1) / 2;
        }
    }
    void downheapify(int p)
    {
        if (hp.size() == 2 && hp[0] < hp[1])
            swap(hp[0], hp[1]);
        else if (hp.size() > 2)
        {
            int n = hp.size();
            int parent_idx = p;
            int left_idx = (2 * parent_idx) + 1;
            int right_idx = (2 * parent_idx) + 2;
            while (left_idx < n)
            {
                int parent = hp[parent_idx];
                int left = hp[left_idx];
                int right = (right_idx < n) ? hp[right_idx] : INT_MIN; // Ensure right_idx is within bounds

                if (left > max(parent, right))
                {
                    swap(hp[parent_idx], hp[left_idx]);
                    parent_idx = left_idx;
                }
                else if (right > max(parent, left))
                {
                    swap(hp[parent_idx], hp[right_idx]);
                    parent_idx = right_idx;
                }
                else
                    break; // If neither child is greater, heap property is satisfied

                left_idx = (2 * parent_idx) + 1;
                right_idx = (2 * parent_idx) + 2;
            }
        }
    }

public:

    int nodeNum()
    {
        return hp.size();
    }
    void insert(int n)
    {
        hp.push_back(n);
        upheapify(hp.size()-1); // upheapify the last index element
    }
    void pop()
    {
        if (hp.size() == 0)
            return;
        swap(hp[0], hp[hp.size() - 1]);
        hp.pop_back();
        downheapify(0);   // downheapify the first element
    }
    void print()
    {
        for (int i = 0; i < hp.size(); i++)
            cout << hp[i] << " ";
        cout << endl;
    }
    int peek()
    {
        if (hp.size() > 0)
            return hp[0];
    }
    void custom_pop(int n)
    {
        for(int i = 0; i < hp.size(); i++)
        {
            if(hp[i] == n)
            {
                hp[i] = INT_MAX;
                upheapify(i);
                pop();
                return;
            }
        }
        cout << "Element not found " << endl;
    }
};

int main()
{
    heap max_heap;
    max_heap.insert(200);
    max_heap.insert(123);
    max_heap.insert(270);
    max_heap.insert(280);
    max_heap.insert(240);
    max_heap.insert(203);
    max_heap.insert(350);
    max_heap.print();
    max_heap.pop();
    max_heap.print();
    max_heap.custom_pop(203);
    max_heap.print();
}