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

    void get_input(string s)
    {
        stringstream ss(s);
        string val;

        while (ss >> val)
        {
            size++;

            node *newNode = new node(stoi(val));
            this->tail = newNode;
            this->tail = this->tail->next;
        }
    }
};
int main()
{
    List list1, list2;

    string n1;
    getline(cin, n1);
    list1.get_input(n1);

    cin.ignore();
    string n2;
    getline(cin, n2);
    list2.get_input(n2);

    if (list1.size == list2.size)
    {
        print("yes");
    }
    else
    {
        print("no");
    }
    print(list1.size);
    print(list2.size);
    return 0;
}