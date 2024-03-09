#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
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
        this->frontNode = this->frontNode->next;
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

class Stack
{
private:
    node *head;
    node *tail;
    int elementSize;

public:
    Stack()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->elementSize = 0;
    }

    void push(int val)
    {
        node *newNode = new node(val);
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
        this->elementSize++;
    }

    int pop()
    {
        if (this->head == nullptr)
        {
            return -1;
        }
        else if (this->head == this->tail)
        {
            node *temp = this->tail;
            this->head = nullptr;
            this->tail = nullptr;
            int data = temp->data;
            delete temp;
            this->elementSize--;
            return data;
        }
        else
        {
            node *temp = this->tail;
            int data = temp->data;

            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
            this->elementSize--;
            return data;
        }
    }

    int top()
    {
        if (this->head != nullptr)
        {
            return tail->data;
        }
        return -1;
    }
    int size()
    {
        return this->elementSize;
    }
    bool empty()
    {
        if (this->head == nullptr)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Stack st;
    Queue que;
    int n, m;
    cin >> n >> m;
    while (n--)
    {
        int i;
        cin >> i;
        st.push(i);
    }
    while (m--)
    {
        int i;
        cin >> i;
        que.push(i);
    }

    bool flag = true;
    if (que.size() != st.size())
    {
        flag = false;
    }
    else
    {
        while (!st.empty())
        {
            if (st.pop() != que.pop())
            {
                flag = false;
                break;
            }
        }
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