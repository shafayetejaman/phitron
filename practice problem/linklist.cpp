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
    node *head;
    node *tail;
    int size;
    List()
    {
        this->head = nullptr;
        this->tail = nullptr;
        size = 0;
    }

    void make_list(string s)
    {
        stringstream ss(s);
        string val;

        while (ss >> val)
        {
            this->size++;

            node *newNode = new node(stoi(val));

            if (this->head == nullptr)
            {
                this->head = newNode;
                this->tail = newNode;
            }
            else
            {
                this->tail->next = newNode;
                this->tail = newNode;
            }
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
    void print_mid()
    {
        if (this->size% 2 == 0)
        {
            
        }
    }
};
int main()
{
    List list1, list2;

    string n1;
    getline(cin, n1);
    list1.make_list(n1);

    string n2;
    getline(cin, n2);
    list2.make_list(n2);

    if (list1.size == list2.size)
    {
        print("yes");
    }
    else
    {
        print("no");
    }

    list1.print();
    list2.print();
    return 0;
}