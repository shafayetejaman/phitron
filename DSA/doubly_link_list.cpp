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
        this->size++;
    }
    void insert(int val, int index)
    {
        node *newNode = new node(val);
        if (index == 0)
        {
            newNode->next = this->head;
            this->head->prev = newNode;
            this->head = this->head->prev;
        }
        else if (index = this->size -1)
        {
            return this->append(val);
        }
        else if (index >= this->size)
        {
            cout << "Invalid Index!\n";
            return;
        }
        else
        {
            node *curr = this->head;
            node *prev = nullptr;
            int count = 0;
            while (curr != nullptr && count < index)
            {
                prev = curr;
                curr = curr->next;
                count++;
            }
            newNode->next = curr;
            curr->prev = newNode;
            prev->next = newNode;
            newNode->prev = prev;
        }
        this->size++;
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
    void delete_node(int index)
    {
        if (index == 0)
        {
            node *temp = this->head;
            this->head = this->head->next;
            this->head->prev = nullptr;
            delete temp;
        }
        else if (index >= this->size)
        {
            cout << "Invalid Index!\n";
            return;
        }
        else if (index == this->size - 1)
        {
            node *temp = this->tail;
            this->tail = this->tail->prev;
            this->tail->next = nullptr;
            delete temp;
        }
        else
        {
            node *curr = this->head->next;
            node *prev = this->head;
            int count = 1;
            while (curr != nullptr && count < index)
            {
                prev = curr;
                count++;
                curr = curr->next;
            }
            prev->next =curr->next;
            curr->next->prev = prev;
            delete curr;
        }
        this->size--;
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