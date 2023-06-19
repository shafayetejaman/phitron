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

class List
{
public:
    node *head;
    node *tail;
    int size;
    List()
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
        if (index > this->size || index < 0)
        {
            cout << "Invalid Index!\n";
            return;
        }
        node *newNode = new node(val);
        if (this->head == nullptr)
        {
            this->head = newNode;
            this->tail = newNode;
        }
        else if (index == 0)
        {
            newNode->next = this->head;
            this->head->prev = newNode;
            this->head = newNode;
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
            newNode->prev = prev;
            if (curr != nullptr)
                curr->prev = newNode;
            prev->next = newNode;
        }
        this->size++;
    }

    void print()
    {
        node *ptr = this->head;
        // cout << "head -> ";
        while (ptr != nullptr)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        // cout << "null" << endl;
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
};

int main()
{
    List list;
    int t;
    cin >> t;

    while (t--)
    {
        int index, val;
        cin >> index >> val;
        list.insert(val, index);
        list.print();
        list.print_reverse();
    }

    return 0;
}