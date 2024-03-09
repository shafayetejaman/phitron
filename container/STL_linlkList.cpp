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
    node *head = nullptr;
    node *tail = nullptr;
    List(int val)
    {
        node *newNode = new node(val);
        this->head = newNode;
        this->tail = newNode;
    }
    List() {}

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
        node *ptr = this->head;
        cout << "head -> ";
        while (ptr != nullptr)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << "null" << endl;
        cout << "tail -> " << tail->data << endl;
    }
    node *insert(int index, int val, node *curr)
    {
        if (index == 0)
        {
            node *newNode = new node(val);
            newNode->next = curr;
            if (curr == nullptr)
            {
                this->tail = newNode;
            }
            return newNode;
        }
        curr->next = insert(index - 1, val, curr->next);
        return curr;
    }
    void insert(int val, int index)
    {
        if (index > this->size() || index < 0)
        {
            cout << "Invalid Index!\n";
            return;
        }
        this->head = this->insert(index, val, this->head);
    }
    int size()
    {
        int count = 0;
        node *ptr = this->head;
        while (ptr != nullptr)
        {
            count++;
            ptr = ptr->next;
        }
        return count;
    }
    void reverse(node *pre, node *curr)
    {
        if (curr == nullptr)
        {
            this->tail = this->head;
            this->tail->next = nullptr;
            this->head = pre;
            return;
        }
        reverse(curr, curr->next);
        curr->next = pre;
    }
};

int main()
{
    list<int> l;

    l.push_back(6);
    l.push_front(9);
    l.push_back(2);

    // cout << *next(l.begin(), 0) << endl;
    for (const auto &i : l)
    {
        cout << i << " ";
    }
    cout << endl;
    // l.erase(next(l.begin(), 0));
    l.sort(greater<int>());

    for (const auto &i : l)
    {
        cout << i << " ";
    }

    // List l;
    // l.append(1);
    // l.append(2);
    // l.append(3);
    // l.append(4);
    // l.append(5);
    // l.insert(10, 5);
    // l.print();



    return 0;
}