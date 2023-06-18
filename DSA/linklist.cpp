#include "my_hederfile.h"

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
        while (ptr != nullptr)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
    void insert(int index, int val)
    {
        node *newNode = new node(val);
        if (index == 0)
        {
            newNode->next = this->head;
            this->head = newNode;
            return;
        }
        else if (index >= this->size())
        {
            cout << "Invalid Index!\n";
            return;
        }
        else if (index == this->size() - 1)
        {
            return this->append(val);
            return;
        }
        node *ptr = this->head;
        node *prev = nullptr;

        while (ptr->next != nullptr && index > 0)
        {
            prev = ptr;
            ptr = ptr->next;
            index--;
        }
        prev->next = newNode;
        newNode->next = ptr;
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
    void delete_node(int index)
    {
        node *ptr = this->head;
        node *prev = nullptr;
        if (index == 0)
        {
            this->head = ptr->next;
            delete ptr;
            return;
        }
        else if (index >= this->size() || index < 0)
        {
            cout << "Invalid Index!\n";
            return;
        }
        else if (index == this->size() - 1)
        {
            while (ptr->next != nullptr)
            {
                prev = ptr;
                ptr = ptr->next;
            }
            prev->next = nullptr;
            this->tail = prev;
            delete ptr;
            return;
        }

        while (ptr->next != nullptr && index > 0)
        {
            prev = ptr;
            ptr = ptr->next;
            index--;
        }
        prev->next = ptr->next;
        delete ptr;
    }
    ~List()
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
    void get_node(int num)
    {
        int input;
        if (this->size() == 0)
        {
            node *ptr = new node(input);
            this->head = ptr;
            this->tail = ptr;

            while (num--)
            {
                cin >> input;
                node *newNode = new node(input);
                ptr->next = newNode;
                ptr = newNode;
            }
        }
        else
        {
            while (num--)
            {
                cin >> input;
                this->append(input);
            }
        }
    }
    // using selection sort
    void sort()
    {
        for (auto i = this->head; i->next != nullptr; i = i->next)
        {
            for (auto j = i; j != nullptr; j = j->next)
            {
                if (i->data > j->data)
                {
                    swap(i->data, j->data);
                }
            }
        }
    }
    void reverse()
    {
        node *curr = this->head->next;
        node *prev = this->head;

        this->head->next = nullptr;

        while (curr != nullptr)
        {
            node *next = curr->next;
            // linking to the left node
            curr->next = prev;
            // updating
            prev = curr;
            curr = next;
        }
        this->head = prev;
    }
};

int main()
{
    List list(1);
    list.append(2);
    list.append(3);
    list.append(4);
    // int num;
    // cout << "node length : ";
    // cin >> num;

    // list.get_node(num);

    // list.print();
    list.insert(3, 30);
    // list.print();
    // cout << list.size() << endl;

    // list.delete_node(6);
    // cout << list.size() << endl;
    // list.reverse();
    list.print();
    list.delete_node(4);
    list.print();
    list.append(5);
    list.print();

    return 0;
}