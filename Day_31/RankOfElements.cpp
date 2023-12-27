#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of elements in array : ";
    cin >> n;

    vector<int> v(n, 0);    // original array
    vector<int> arr(n, 0);  // extra space : O(n)
    cout << "Enter the elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        arr[i] = v[i];
    }

    sort(arr.begin(), arr.end());
    // constructing map
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]] = i;
    }
    // updating values in array
    for (int i = 0; i < n; i++)
    {
        v[i] = m[v[i]];
        cout << v[i] << " ";
    }
}