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
    node *head;
    node *tail;
    int size;
    Stack()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

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
            if (curr->prev != nullptr)
            {
                cout << curr->data << endl
                     << "^" << endl;
            }
            else
            {
                cout << curr->data << endl;
            }

            curr = curr->prev;
        }
    }
    int pop()
    {
        if (this->head == nullptr)
        {
            cout << "The stack is empty!" << endl;
        }
        else
        {
            node *temp = this->tail;
            int data = temp->data;

            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
            return data;
        }
        return -1;
    }
    int top()
    {
        if (this->head == nullptr)
        {
            cout << "The stack is empty!" << endl;
        }
        else
        {
            return tail->data;
        }
        return -1;
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
    stack.pop();
    stack.pop();
    stack.print();
    // cout << stack.top();

    return 0;
}