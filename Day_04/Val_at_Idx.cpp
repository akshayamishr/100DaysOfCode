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

    int val_at_idx(int idx)
    {
        if (idx > size || idx < 0)
        {
            cout << "INDEX OUT OF BOUND !!!";
            return -1;
        }
        else if (idx == 0)
            return head->val;
        else if (idx == size)
            return tail-> val;
        else
        {
            Node *temp = head;
            for (int i = 1; i <= idx; i++)
            {
                temp = temp->next;
            }
            return temp->val;
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
    list.insert_at_end(10);
    list.display();
    list.insert_at_end(20);
    list.display();
    list.insert_at_end(30);
    list.display();
    list.insert_at_end(40);
    list.display();
    cout << list.size << endl;
    cout << list.val_at_idx(3);
}