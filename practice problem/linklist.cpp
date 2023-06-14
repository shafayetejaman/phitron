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

class List
{
public:
    node *head = nullptr;
    List(int val)
    {
        node *newNode = new node(val);
        head = newNode;
    }
    List() {}
};
int main()
{

    return 0;
}