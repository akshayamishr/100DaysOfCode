#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<string, float> m;
    // inserting pairs
    m["Dashing"] = 5.0;
    m["War Lord"] = 4.99;
    m["Prince Kymar"] = 4.98;

    for (auto ele : m)
    {
        cout << ele.first << " " << ele.second << endl;
    }
    cout << m.size() << endl;
    
    // deleting a pair
    m.erase("War Lord");
    for (auto ele : m)
    {
        cout << ele.first << " " << ele.second << endl;
    }
    cout << m.size() << endl;
}