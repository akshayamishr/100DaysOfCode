#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of elements in array : ";
    cin >> n;
    vector<int> v(n, 0);
    cout << "Enter the elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    float kmin = (float)(INT_MIN);
    float kmax = (float)(INT_MAX);
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] > v[i + 1])
            kmin = max(kmin, (v[i] + v[i + 1]) / (float)(2));
        else
            kmax = min(kmax, (v[i] + v[i + 1]) / (float)(2));
        if (kmin > kmax)
        {
            cout << "-1";
            return 0;
        }
    }
    if (kmin == kmax)
    {
        if (kmin - (int)(kmin) == 0) /// kmin is an integer
            cout << "the value of k is : " << kmin;
        else
            cout << "-1";
    }
    else
    {
        if (kmin - (int)(kmin) > 0)   // if kmin is not an integer making it integer
            kmin = (int)(kmin + 1);
        cout << "Range of k : " << kmin << " to " << (int)(kmax);
    }
}