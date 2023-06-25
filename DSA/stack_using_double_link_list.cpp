#include "my_hederfile.h"

using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class Stack
{
public:
    node *head = nullptr;
    node *tail = nullptr;

    void push(int val)
    {
        node *newNode = new node(val);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = tail->next;
        }
    }
    void print()
    {
        node *curr = this->tail;
        while (curr != nullptr)
        {
            cout << curr->data << endl
                 << "↓" << endl;
            curr = curr->prev;
        }
    }
};

int main()
{
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.print();

    return 0;
}