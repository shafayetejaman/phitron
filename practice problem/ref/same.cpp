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
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
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
        cin >> val;
        if (val == -1)
        {
            break;
        }
        append(head, val);
    }
    return head;
}

void print(node *&head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
}


int main()
{
    node *list1 = make_list();
    print(list1);

    return 0;
}