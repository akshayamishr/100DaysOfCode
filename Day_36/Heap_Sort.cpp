#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class MaxHeap
{
private:
    vector<int> hp;
    void upheapify(int n)
    {
        int child_idx = n;
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
    void downheapify(int p, int bound) // Added the bound parameter
    {
        if (hp.size() == 2 && hp[0] < hp[1])
            swap(hp[0], hp[1]);
        else if (hp.size() > 2)
        {
            int n = bound;
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
    MaxHeap(vector<int> &v)
    {
        hp = v;
        int n = hp.size();
        // O(n)
        // we don't have to downheapify leaf nodes
        for (int j = n / 2; j >= 0; j--)
        {
            downheapify(j, n);
        }
    }

    void heapSort()
    {
        int n = hp.size();
        for (int i = n - 1; i > 0; i--)
        {
            swap(hp[0], hp[i]);
            downheapify(0, i);
        }
    }

    vector<int> sortedArray()
    {
        return hp;
    }
};

void HeapSort(vector<int> &v)
{
    int n = v.size();
    MaxHeap hp(v);
    hp.heapSort();
    v = hp.sortedArray();
}

int main()
{
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    vector<int> v(n, 0);
    cout << "Enter the elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    HeapSort(v);
    cout << "Sorted array " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}