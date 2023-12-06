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
    int target;
    cout << "Enter the target element : ";
    cin >> target;
    int hi = n - 1, lo = 0, mid;
    while (hi >= lo)
    {
        mid = lo + (hi - lo) / 2;
        if (arr[mid] == target)
        {
            cout << "Target Found at " << mid << "th index";
            return 0;
        }
        else if (arr[mid] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    cout << "Target not found ";
}