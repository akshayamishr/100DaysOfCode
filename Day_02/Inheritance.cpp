#include <iostream>
using namespace std;
class A
{
private:
    int a_private = 0;      // neither be accessed outside the class nor be inherited

protected:
    int a_protected = 0;    // can't be accessed outside the class but it can be inherited

public:
    int a_public = 0;       // can be accessed as well as can be inherited
};

class B : public A
{
public:
    int change()
    {
        a_public = 1;
        return a_public;
    }
};

int main()
{
    B b;
    cout << b.change() << endl;
}