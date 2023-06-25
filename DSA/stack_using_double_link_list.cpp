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
        node *curr = this->head;
        while (curr != nullptr)
        {
            cout << curr->data << endl << "";
        }
    }
};

int main()
{


    return 0;
}