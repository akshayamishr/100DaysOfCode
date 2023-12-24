#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(23);
    s.insert(4);
    s.insert(23);
    // elements are randomly stored
    // no two elements will have same values
    // if we reinsert any existing value into the set it'll also not change the size
    for (int ele : s)
    {
        cout << ele << " ";
    }
    cout << "\n" << s.size() << endl;
    cout << s.count(23) << endl;

    // s.find() searches the set for the target value
    // if target doesn't found it'll return the s.end();
    int target = 23;
    if (s.find(target) != s.end())
        cout << "Element found " << endl;
    else
        cout << "Element not found " << endl;
}
