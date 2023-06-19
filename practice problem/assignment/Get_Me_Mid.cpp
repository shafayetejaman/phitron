#include <bits/stdc++.h>

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
    node *tail;
    int size;

    List()
    {
        this->head = nullptr;
        this->tail = nullptr;
        size = 0;
    }
    void get_data(int val)
    {
        node *newNode = new node(val);
        if (this->head == nullptr)
        {
            this->head = newNode;
            this->tail = newNode;
        }
        else
        {
            this->tail->next = newNode;
            this->tail = this->tail->next;
        }
        size++;
    }
    void sort()
    {
        for (auto i = this->head; i->next != nullptr; i = i->next)
        {
            for (auto j = i->next; j != nullptr; j = j->next)
            {
                if (i->data < j->data)
                {
                    swap(i->data, j->data);
                }
            }
        }
    }
    void print_mid()
    {
        if (this->size % 2 == 0)
        {
            node *ptr = this->head;
            node *prev = nullptr;
            int count = 0;
            while (count < (this->size / 2))
            {
                prev = ptr;
                ptr = ptr->next;
                count++;
            }
            cout << prev->data << " " << ptr->data << endl;
        }
        else
        {
            node *ptr = this->head;

            int count = 0;
            while (count < (this->size / 2))
            {
                count++;
                ptr = ptr->next;
            }
            cout << ptr->data << endl;
        }
    }
};
int main()
{
    List list;

    while (true)
    {
        int input;
        cin >> input;
        if (input == -1)
        {
            break;
        }
        list.get_data(input);
    }
    list.sort();
    list.print_mid();

    return 0;
}