#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int n) : val(n), next(NULL) {}
};
int main()
{
    // creating nodes 100,200,300
    Node a(100);
    Node b(200);
    Node c(300);
    // creating linkelist
    a.next = &b;
    b.next = &c;

    cout << a.val << endl;
    cout << (*(a.next)).val << endl;
    // printing value of c with b
    cout << (b.next)->val << endl;
    // printing value of c with a
    cout << ((a.next)->next)->val << endl;

    // printing values through loop
    cout << "Loop :" << endl;
    Node temp = a;
    while (1)
    {
        cout << temp.val << " ";
        if (temp.next == NULL)
            break;
        temp = *(temp.next);
    }
}