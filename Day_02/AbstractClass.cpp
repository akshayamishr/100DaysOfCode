#include<iostream>
using namespace std;
class A{
    public:
    virtual void print() = 0; // pure virtual function
    virtual void num(int a) = 0;
};
class B : public A{
    public:
    void print(){
        cout << "This was pure virtual function in A " << endl;
    }
    void num(int a){
        cout << ++a << endl;
    }
};
int main()
{
    B b;
    b.print();
    b.num(3);
}