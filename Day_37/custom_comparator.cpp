#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

bool cc(int a, int b)
{
    return a > b;  // if (a > b) or true  -->  pick a 
}

int main()
{
    vector<int> v = {9, 7, 1, 3, 0, 4};
    sort(v.begin(), v.end(), cc);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}