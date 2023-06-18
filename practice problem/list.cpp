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

    List(node *head)
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    void append(int val)
    {
        node *newNode = new node(val);

        
    }
};

int main()
{


    return 0;
}