#include <iostream>
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
    // Bubble Sort
    // bubbling the largest element to the end in every pass
    for (int i = 0; i < n - 1; i++)  // n-1 passes
    {
        bool flag = true;
        for (int j = 0; j < n - 1 - i; j++)  // comparing elements
        {
            if (arr[j] > arr[j + 1])
            {
                flag = false;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (flag)
            break;
    }
    //
    cout << "Sorted array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}