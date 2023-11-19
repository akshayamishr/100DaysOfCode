#include<iostream>
using namespace std;
class A{
    public : 
    void print()
    {
        cout << "Function of A" << endl;
    }
};
class B : public A{
    public:
    virtual void print(){
        cout << "Overriding in B " << endl;
    }
};
class C : public B{
    public : 
    void print(){
        cout << "Overriding in C "<< endl;
    }
};
int main()
{
    A a;
    a.print();
    B b;
    b.print();
    // compile time bindin
    A *d;
    d = &b;
    d->print();
    // run time binding
    B *e;
    C c;
    e = &c;
    e->print();
}