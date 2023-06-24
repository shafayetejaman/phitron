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
node *make_copy(node *oldHead)
{
    node *head = nullptr;
    node *tail = nullptr;

    head = new node(oldHead->data);
    tail = head;
    oldHead = oldHead->next;

    while (oldHead != nullptr)
    {
        node *newNode = new node(oldHead->data);

        tail->next = newNode;
        tail = tail->next;
        oldHead = oldHead->next;
    }
    return head;
}

void reverse(node *&head, node *prev, node *curr)
{
    if (curr == nullptr)
    {
        head = prev;
        return;
    }
    reverse(head, curr, curr->next);
    curr->next = prev;
}

int main()
{
    node *head = make_list();
    node *copy = make_copy(head);

    reverse(head, nullptr, head);
    bool flag = true;
    while (head != nullptr)
    {
        if(head->data != copy->data)
        {
            flag = false;
            break;
        }
        head = head->next;
        copy = copy->next;
    }
    if (flag)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }


    return 0;
}