#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int n) : val(n), next(NULL) {}
};
class linked_list
{
public:
    int size;
    Node *head;
    Node *tail;
    linked_list() : head(NULL), tail(NULL), size(0){};

    void insert_at_begin(int n)
    {
        Node *temp = new Node(n);
        if (size == 0)
            head = tail = temp;
        else
        {
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void insert_at_end(int n)
    {
        Node *temp = new Node(n);
        if (size == 0)
            head = tail = temp;
        else
        {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void insert(int idx, int n)
    {
        if (idx > size || idx < 0)
            cout << "INDEX OUT OF BOUND !!!";
        else if (idx == 0)
            insert_at_begin(n);
        else if (idx == size)
            insert_at_end(n);
        else
        {
            Node *t = new Node(n);
            Node *temp = head;
            for (int i = 1; i <= idx - 1; i++)
            {
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            size++;
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    linked_list list;
    list.insert_at_begin(10);
    list.display();
    list.insert_at_end(20);
    list.display();
    list.insert(2,30);
    list.display();
    cout << list.size;
}