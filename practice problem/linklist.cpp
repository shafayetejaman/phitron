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
    node *tail = nullptr;
    List(int val)
    {
        node *newNode = new node(val);
        head = newNode;
        tail = newNode;
    }
    List() {}
    void get_input(int n)
    {
        while (n--)
        {
            int val;
            cin >> val;
            node *newNode = new node(val);
            tail->next = newNode;
            tail = tail->next;
        }
    }
};
int main()
{

    return 0;
}