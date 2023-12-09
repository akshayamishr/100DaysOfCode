#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int n) : val(n), next(NULL) {}
};
class Queue
{
public:
    int size;
    Node *head;
    Node *tail;
    Queue() : head(NULL), tail(NULL), size(0){};

    void push(int n)
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

    void pop()
    {
        if (size == 0)
        {
            cout << "There is no element in the queue" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        size--;
        delete(temp); // deleting the previous head
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
};
int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.display();
    cout << "Top element is : " << q.front() << endl;
    cout << "Size of queue : " << q.size_() << endl;
    cout << "Back element is : " << q.back() << endl;
    q.pop();
    q.pop();
    q.pop();
    cout << "Size of queue after popping : " << q.size_() << endl;
    q.display();
    q.pop();
    cout << q.empty() << endl;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.display();
    cout << "Size of queue : " << q.size_() << endl;
}