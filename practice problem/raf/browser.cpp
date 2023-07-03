#include <iostream>
using namespace std;

class Node
{
public:
    string val;
    Node *next;
    Node *prv;
    Node(string val)
    {
        this->val = val;
        this->next = nullptr;
        this->prv = nullptr;
    }
};

void insert(Node *&head, Node *&tail, string val)
{
    Node *newnode = new Node(val);
    if (head == nullptr)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prv = tail;
        tail = newnode;
    }
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

Node *visit(Node *head, string value, Node *lastVisited)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->val == value)
        {
            cout << temp->val << endl;
            lastVisited = temp;
            return temp;
        }
        temp = temp->next;
    }
    cout << "Not Available" << endl;
    return nullptr;
}

void moveToPrevious(Node *&current)
{
    if (current != nullptr && current->prv != nullptr)
    {
        current = current->prv;
        cout << current->val << endl;
    }
    else
    {
        cout << "Not Available" << endl;
    }
}

void moveToNext(Node *&current)
{
    if (current != nullptr && current->next != nullptr)
    {
        current = current->next;
        cout << current->val << endl;
    }
    else
    {
        cout << "Not Available" << endl;
    }
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    Node *current = nullptr;     // Pointer to the current node
    Node *lastVisited = nullptr; // Pointer to the last valid visited node
    string val;
    while (true)
    {
        cin >> val;
        if (val == "end")
        {
            break;
        }
        insert(head, tail, val);
        if (current == nullptr)
        {
            current = head; // Set the current node to the head initially
        }
    }

    int count = 0, n;
    cin >> n;
    string command;
    while (count < n)
    {
        cin >> command;
        if (command == "end")
        {
            break;
        }
        else if (command == "visit")
        {
            string value;
            cin >> value;
            current = visit(head, value, lastVisited);
            if (current == lastVisited)
            {
                lastVisited = nullptr; // Reset lastVisited if it was not updated
            }
        }
        else if (command == "prev")
        {
            moveToPrevious(current);
        }
        else if (command == "next")
        {
            moveToNext(current);
        }
        else
        {
            cout << "Not Available" << endl;
        }
        count++;
    }

    return 0;
}
