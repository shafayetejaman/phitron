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

class DLL
{
public:
    node *head;
    node *tail;
    DLL()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    void append(int val)
    {
        node *newNode = new node(val);
        newNode->prev = this->tail;
        this->tail->next = newNode;
        this->tail = this->tail->next;
    }
};

int main()
{

    return 0;
}