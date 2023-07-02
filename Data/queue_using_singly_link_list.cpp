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
    node *frontNode = nullptr;
    node *backNode = nullptr;

    queue(int data)
    {
        node *newNode = new node(data);
        this->frontNode = newNode;
        this->backNode = newNode;
    }

    void push(int data)
    {
        node *newNode = new node(data);
        this->backNode->next = newNode;
        this->backNode = newNode;
    }

    int pop()
    {
        node *temp = this->frontNode;
        this->frontNode = this->frontNode->next;
        int data = temp->data;
        delete temp;
        return data;
    }
};

int main()
{


    return 0;
}