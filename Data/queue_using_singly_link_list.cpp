#include "my_hederfile.h"

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class queue
{
public:
    Node *frontNode = nullptr;
    Node *backNode = nullptr;

    queue(int data)
    {
        Node *newNode = new Node(data);
        this->frontNode = newNode;
        this->backNode = newNode;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        this->backNode->next = newNode;
        this->backNode = newNode;
    }

    int pop()
    {
        Node *temp = this->frontNode;
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