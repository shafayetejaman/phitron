#include "my_hederfile.h"

using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class queue
{
public:
    node *front = nullptr;
    node *back = nullptr;

    queue(int data)
    {
        node *newNode = new node(data);
        this->front = newNode;
        this->back = newNode;
    }

    void push(int data)
    {
        node *newNode = new node(data);
        this->back->next = newNode;
        this->back = newNode;
    }

    int pop()
    {
        node *temp = this->front;
        this->front = this->front->next;
        int data = temp->data;
        delete temp;
        return data;
    }
};

int main()
{


    return 0;
}