#include <bits/stdc++.h>

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

int size(node *head)
{
    int count = 0;
    while (head != nullptr)
    {
        count++;
        head = head->next;
    }
    return count;
}

void insert(node *&head, int index, int val, node *&tail)
{
    node *newNode = new node(val);
    if (index == 0)
    {
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            head->prev = newNode;
            newNode->next = head;
            head = head->prev;
        }
    }
    else if (index == size(head))
    {
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = tail->next;
        }
    }
    else if (index > 0 && index < size(head))
    {
        node *curr = head;
        node *prev = nullptr;
        while (index--)
        {
            prev = curr;
            curr = curr->next;
        }
        newNode->next = curr;
        curr->prev = newNode;
        newNode->prev = prev;
        prev->next = newNode;
    }
    else
    {
        cout << "Invalid" << endl;
    }
}

void print_l(node *head)
{
    cout << "L -> ";
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void print_r(node *tail)
{
    cout << "R -> ";
    while (tail != nullptr)
    {
        cout << tail->data << " ";
        tail = tail->prev;
    }
    cout << endl;
}

int main()
{
    int index;
    int val;
    int t;
    cin >> t;
    node *head = nullptr;
    node *tail = nullptr;

    while (t--)
    {
        cin >> index >> val;
        if (index >= 0 && index <= size(head))
        {
            insert(head, index, val, tail);

            print_l(head);
            print_r(tail);
        }
        else
        {
            cout << "Invalid" << endl;
        }
    }

    return 0;
}