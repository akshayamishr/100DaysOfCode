#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the element : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // Selection Sort
    // selectin the smallest element
    for (int i = 0; i < n - 1; i++) // traversing the array
    {
        int temp = INT_MAX;
        int temp_idx = -1;
        for (int j = i; j < n; j++) // finding the smallest element from index i to n-1
        {
            if (arr[j] < temp)
            {
                temp = arr[j];
                temp_idx = j;
            }
        }
        swap(arr[i], arr[temp_idx]);
    }
    //
    cout << "Sorted array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}