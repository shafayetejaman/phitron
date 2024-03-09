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

class DLL
{
public:
    node *head;
    node *tail;
    int size;
    DLL()
    {
        this->head = nullptr;
        this->tail = nullptr;
        size = 0;
    }
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
            newNode->prev = this->tail;
            this->tail->next = newNode;
            this->tail = this->tail->next;
        }
        this->size++;
    }
    void insert(int val, int index)
    {
        node *newNode = new node(val);
        if (index == 0)
        {
            newNode->next = this->head;
            this->head->prev = newNode;
            this->head = this->head->prev;
        }
        else if (index == this->size - 1)
        {
            return this->append(val);
        }
        else if (index >= this->size || index < 0)
        {
            cout << "Invalid Index!\n";
            return;
        }
        else
        {
            node *curr = this->head;
            node *prev = nullptr;
            int count = 0;
            while (curr != nullptr && count < index)
            {
                prev = curr;
                curr = curr->next;
                count++;
            }
            newNode->next = curr;
            curr->prev = newNode;
            prev->next = newNode;
            newNode->prev = prev;
        }
        this->size++;
    }

    void print()
    {
        node *ptr = this->head;
        cout << "head -> ";
        while (ptr != nullptr)
        {
            cout << ptr->data << " <-> ";
            ptr = ptr->next;
        }
        cout << "null" << endl;
    }
    void print_reverse()
    {
        node *ptr = this->tail;
        while (ptr != nullptr)
        {
            cout << ptr->data << " ";
            ptr = ptr->prev;
        }
        cout << endl;
    }
    void delete_node(int index)
    {
        if (this->head == nullptr)
        {
            cout << "List is empty!\n";
            return;
        }
        if (index == 0)
        {
            node *temp = this->head;
            this->head = this->head->next;
            delete temp;
            if (this->head == nullptr)
            {
                this->tail = nullptr;
                return;
            }
            this->head->prev = nullptr;
        }
        else if (index >= this->size || index < 0)
        {
            cout << "Invalid Index!\n";
            return;
        }
        else if (index == this->size - 1)
        {
            node *temp = this->tail;
            this->tail = this->tail->prev;
            this->tail->next = nullptr;
            delete temp;
        }
        else
        {
            node *curr = this->head->next;
            node *prev = this->head;
            int count = 1;
            while (curr != nullptr && count < index)
            {
                prev = curr;
                count++;
                curr = curr->next;
            }
            prev->next = curr->next;
            curr->next->prev = prev;
            delete curr;
        }
        this->size--;
    }
    ~DLL()
    {
        node *ptr = this->head;
        node *prev = nullptr;
        while (ptr != nullptr)
        {
            prev = ptr;
            ptr = ptr->next;
            delete prev;
        }
        cout << "All the nodes have been freed\n";
    }
    void add(DLL &list)
    {
        this->tail->next = list.head;
        list.head = this->tail;
        this->size += list.size;
    }
    void reverse()
    {
        node *i = this->head;
        node *j = this->tail;

        while (i->next != j && i != j)
        {
            swap(i->data, j->data);
            i = i->next;
            j = j->prev;
        }
        swap(i->data, j->data);
    }
};

int main()
{
    DLL list, temp;


    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    // list.print();
    // // list.insert(10, 0);

    // temp.append(10);
    // temp.append(20);
    // temp.append(30);
    // temp.append(40);
    // temp.append(50);
    list.print();
    // temp.print();

    // list.add(temp);
    // list.print();
    // print(list.size);
    // list.append(1);
    // list.delete_node(0);
    list.reverse();
    list.print();

    // list.print_reverse();

    return 0;
}