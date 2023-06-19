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

void same(node *list1, node *list2)
{
    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->data != list2->data)
        {
            cout << "NO";
            return;
        }
        list1 = list1->next;
        list2 = list2->next;
    }
    if (list1 == nullptr && list2 == nullptr)
        cout << "YES";
    else
        cout << "NO";
}

int main()
{
    node *list1 = make_list();
    node *list2 = make_list();
    print(list1);
    print(list2);

    same(list1, list2);

    return 0;
}