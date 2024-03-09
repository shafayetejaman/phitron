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
    void get_data(int val, int x)
    {
        node *newNode = new node(val);
        if (this->head == nullptr)
        {
            this->head = newNode;
            this->tail = newNode;
        }
        else if (x == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            this->tail->next = newNode;
            this->tail = this->tail->next;
        }
    }
    void print()
    {
        cout << this->head->data << " " << this->tail->data << endl;
    }
};

int main()
{
    List list;
    int t;
    cin >> t;

    while (t--)
    {
        int input, x;
        cin >> x >> input;
        if (input == -1)
        {
            break;
        }
        list.get_data(input, x);
        list.print();
    }

    return 0;
}