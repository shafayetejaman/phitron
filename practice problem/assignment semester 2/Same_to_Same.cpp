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
    int max = INT_MIN;
    int min = INT_MAX;
    int size;

    List()
    {
        this->head = nullptr;
        this->tail = nullptr;
        size = 0;
    }
    void get_data(int val)
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

        size++;
    }
};
bool same(List &list1, List &list2)
{
    if (list1.size != list2.size)
    {
        return false;
    }
    node *ptr1 = list1.head;
    node *ptr2 = list2.head;

    while (ptr1 != nullptr)
    {
        if (ptr1->data != ptr2->data)
        {
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return true;
}
int main()
{
    List list1;
    List list2;
    int t = 2;

    while (t--)
    {
        while (true)
        {
            int input;
            cin >> input;
            if (input == -1)
            {
                break;
            }
            if (t == 1)
            {
                list1.get_data(input);
            }
            else
            {
                list2.get_data(input);
            }
        }
    }

    if (same(list1, list2))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
  

    return 0;
}