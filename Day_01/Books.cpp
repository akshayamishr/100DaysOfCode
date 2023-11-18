#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    int price;
    int pages;
    string name;

public:
    void get(int p, int pa, string na)
    {
        pages = pa;
        price = p;
        name = na;
    }

    int count(int p)
    {
        if (p <= price)
            return 1;
        return 0;
    }
    bool isBook(string n)
    {
        if (n == name)
            return true;
        return false;
    }
};

int main()
{
    Book Harry_Potter;
    Harry_Potter.get(1000, 500, "Half Blood Prince");
    cout << Harry_Potter.count(500) << endl;
    cout << Harry_Potter.isBook("Chamber of Secrets");
}