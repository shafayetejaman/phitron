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
    node *head;
    List(int val)
    {
        node *newNode = new node(val);
        head = newNode;
    }

    void append(int val)
    {
        node *newNode = new node(val);
        node *ptr = this->head;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
    void print()
    {
        node *ptr = this->head;
        while (ptr != nullptr)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main()
{
    List l(1);
    l.append(2);
    l.append(3);
    l.append(4);
    l.append(5);
    l.print();

    return 0;
}