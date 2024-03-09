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

node *make_list()
{
    node *head = nullptr;
    node *tail = nullptr;

    int val;
    cin >> val;

    if (val != -1)
    {
        head = new node(val);
        tail = head;
    }
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        node *newNode = new node(val);

        tail->next = newNode;
        tail = tail->next;
    }
    return head;
}
void remove(node *&head)
{
    node *curr = head;
    while (curr->next != nullptr)
    {
        if (curr->data == curr->next->data)
        {
            node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }
}
void sort(node *&head)
{
    for (auto i = head; i != nullptr; i = i->next)
    {
        for (auto j = i->next; j != nullptr; j = j->next)
        {
            if (i->data > j->data)
            {
                swap(i->data, j->data);
            }
        }
    }
}
void print(node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    node *head = make_list();
    sort(head);
    remove(head);
    print(head);

    return 0;
}