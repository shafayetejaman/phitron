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

    }
};
void reverse(node *&head)
{
    if (head == nullptr)
    {
        return;
    }
    reverse(head->next);
    cout << head->data << " ";
}
void print(node *&head)
{
    if (head == nullptr)
    {
        return;
    }
    cout << head->data << " -> ";
    print(head->next);
}
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
    reverse(list.head);
    cout << endl;
    print(list.head);

    return 0;
}