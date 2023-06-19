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

void append(node *&head, int val)
{
    node *newNode = new node(val);
    node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

node *make_list()
{
    node *head = nullptr;

    int val;
    while (true)
    {
        if (val == -1)
        {
            break;
        }
        cin >> val;
        append(head, val);
    }
    return head;
}

void print(node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
    }
    cout << endl;
}


int main()
{





    return 0;
}