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
    List(int val)
    {
        node *newNode = new node(val);
        head = newNode;
    }
    List() {}

    void append(int val)
    {
        node *newNode = new node(val);
        if (this->size() == 0)
        {
            this->head = newNode;
            return;
        }
        node *ptr = this->head;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
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
            // return this->append(val);
            cout << "Invalid Index!\n";
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
            // deleting the last node
            // while (ptr->next != nullptr)
            // {
            //     prev = ptr;
            //     ptr = ptr->next;
            // }
            // prev->next = nullptr;
            // delete ptr;

            cout << "Invalid Index!\n";
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
            this->head = new node(input);
            node *ptr = this->head;

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
    void sort()
    {
        node *i = this->head;
        node *j = i;
        while (i->next->next != nullptr)
        {
            while (j->next->next != nullptr)
            {
                if (j->data > j->next->data)
                swap(j->data, j->next->data);
            }
            j = this->head;
        }
    }
};

int main()
{
    List list(10);
    list.append(2);
    list.append(6);
    list.append(8);
    list.append(5);
    // int num;
    // cout << "node length : ";
    // cin >> num;

    // list.get_node(num);

    // list.print();
    // list.insert(9, 30);
    // list.print();
    // cout << list.size() << endl;

    // list.delete_node(6);
    // cout << list.size() << endl;
    list.sort();
    list.print();

    return 0;
}