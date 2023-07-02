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
    
};

int main()
{


    return 0;
}