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

    void get_input(int n)
    {
        size += n;
        while (n--)
        {
            int val;
            cin >> val;
            node *newNode = new node(val);
            this->tail = newNode;
            this->tail = this->tail->next;
        }
    }
};
int main()
{
    List list1, list2;

    int n1;
    cin >> n1;
    list1.get_input(n1);

    int n2;
    cin >> n2;
    list2.get_input(n2);

    print(list1.size);
    print(list2.size);

    return 0;
}