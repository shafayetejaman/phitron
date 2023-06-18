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
    int size;
    DLL()
    {
        this->head = nullptr;
        this->tail = nullptr;
        size = 0;
    }
    void append(int val)
    {
        node *newNode = new node(val);
        if (this->head == nullptr)
        {
            this->head = newNode;
            this->tail = newNode;
        }
        else
        {
            newNode->prev = this->tail;
            this->tail->next = newNode;
            this->tail = this->tail->next;
        }
    }
    void insert(int val, int pos)
    {
        node *newNode = new node(val);
        node *curr = this->head->next;
        node *prev = this->head;
        int count = 1;
        while (curr != nullptr && count < pos)
        {
            prev = curr;
            count++;
            curr = curr->next;
        }
        newNode->next = curr;
        curr->prev = newNode;
        prev->next = newNode;
        newNode->prev = prev;
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
    void print_reverse()
    {
        node *ptr = this->tail;
        while (ptr != nullptr)
        {
            cout << ptr->data << " ";
            ptr = ptr->prev;
        }
        cout << endl;
    }
    void reverse()
    {
        node *curr = this->head;
        node *prev = nullptr;
        node *next = nullptr;

        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        this->head->next = nullptr;
        
    }
};

int main()
{
    DLL list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.print();
    list.insert(10, 3);
    list.print();
    // list.print_reverse();

    return 0;
}