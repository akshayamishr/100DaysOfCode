#include <iostream>
using namespace std;
class compare
{
private:
    int a;
    int b;

public:
    compare(int a, int b)
    {
        cout << max(a, b) << " is larger " << endl;
    }
    compare(int a, int b, int c)
    {
        cout << max(max(a, b),c) << " is largest " << endl;
    }
};

int main()
{
    compare nums_1(3,4);
    compare nums_2(3,4,5);
}