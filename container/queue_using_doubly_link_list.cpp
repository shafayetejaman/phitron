#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class Queue
{
private:
    Node *frontNode = nullptr;
    Node *backNode = nullptr;
    int elementSize = 0;

public:
    Queue(int data)
    {
        Node *newNode = new Node(data);
        this->frontNode = newNode;
        this->backNode = newNode;
        this->elementSize++;
    }
    Queue() {}

    void push(int data)
    {
        Node *newNode = new Node(data);
        if (this->frontNode == nullptr)
        {
            this->frontNode = newNode;
            this->backNode = newNode;
            this->elementSize++;
        }
        else
        {

            this->backNode->next = newNode;
            newNode->prev = this->backNode;
            this->backNode = newNode;
            this->elementSize++;
        }
    }

    int pop()
    {
        if (this->frontNode == nullptr)
        {
            cout << "the queue is empty";
            return -1;
        }
        Node *temp = this->frontNode;
        if (this->frontNode == this->backNode)
        {
            this->frontNode = nullptr;
            this->backNode = nullptr;
        }
        else
        {
            this->frontNode = this->frontNode->next;
            this->frontNode->prev = nullptr;
        }
        int data = temp->data;
        delete temp;
        this->elementSize--;
        return data;
    }
    int front()
    {
        return this->frontNode->data;
    }
    int back()
    {
        return this->backNode->data;
    }
    bool empty()
    {
        if (this->frontNode == nullptr)
        {
            return true;
        }
        return false;
    }
    int size()
    {
        return elementSize;
    }
};

int main()
{
    Queue queue(1);
    for (auto i = 2; i <= 5; i++)
    {
        queue.push(i); // 1 2 3  4 5
    }
    while (!queue.empty())
    {
        cout << queue.pop() << " " << queue.size() << endl;
    }
    for (auto i = 2; i <= 5; i++)
    {
        queue.push(i); // 1 2 3  4 5
    }
    while (!queue.empty())
    {
        cout << queue.pop() << " " << queue.size() << endl;
    }

    return 0;
}