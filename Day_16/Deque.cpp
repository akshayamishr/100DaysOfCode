#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
class Deque
{
public:
    int size;
    Node *head;
    Node *tail;
    Deque() : head(NULL), tail(NULL), size(0){};

    void push_front(int n)
    {
        Node *temp = new Node(n);
        if (size == 0)
            head = tail = temp;
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }

    void push_back(int n)
    {
        Node *temp = new Node(n);
        if (size == 0)
            head = tail = temp;
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    void pop_front()
    {
        if (size == 0)
        {
            cout << "There is no element in the list";
            return;
        }
        head->next->prev = NULL;
        if (head != NULL)
            head = head->next;
        if (head == NULL)
            tail = NULL;
        size--;
    }

    void pop_back()
    {
        if (size == 0)
        {
            cout << "Empty List";
            return;
        }
        else if (size == 1)
        {
            pop_front();
            return;
        }
        else
        {
            Node *temp = tail->prev;
            temp->next = NULL;
            tail = temp;
            size--;
            return;
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

    int size_()
    {
        return size;
    }

    bool empty()
    {
        return size == 0;
    }

    int front()
    {
        if (size == 0)
        {
            cout << "Queue is empty";
            return -1;
        }
        return head->val;
    }

    int back()
    {
        if (size == 0)
        {
            cout << "Queue is empty";
            return -1;
        }
        return tail->val;
    }
};

int main()
{
    Deque q;
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.display();
    q.pop_back();
    q.pop_front();
    q.display();
    q.push_front(1);
    q.display();
    cout << "size : " << q.size_() << endl;
    cout << "Front : " << q.front() << endl;
    cout << "Back : " << q.back() << endl;
}