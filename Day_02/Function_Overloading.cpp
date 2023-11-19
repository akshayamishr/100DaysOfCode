#include <iostream>
using namespace std;
class adder
{
public:
    int add(int a, int b) { return a + b; }
    int add(int a, int b, int c) { return a + b + c; }
    int add(int a, double b) { return a + b; }
    // either change the number of arguments or change their data type
};

int main()
{
    adder inputs;
    cout << inputs.add(3, 4) << endl;
    cout << inputs.add(3, 4, 5) << endl;
    cout << inputs.add(3, 4.5) << endl;
}