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

    List()
    {
        this->head = nullptr;
        this->tail = nullptr;
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
            this->tail->next = newNode;
            this->tail = this->tail->next;
        }
    }
    void print()
    {
        node *temp = this->head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null";
    }
};

int main()
{
    List list;

    int val;

    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        list.append(val);
    }

    list.print();

    return 0;
}