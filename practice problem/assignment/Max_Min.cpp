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

    List()
    {
        this->head = nullptr;
        this->tail = nullptr;

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
        if (val < min)
        {
            min = std::min(min, val);
        }
        if (val > max)
        {
            max = std::max(max, val);
        }
    }

};
int main()
{
    List list;

    while (true)
    {
        int input;
        cin >> input;
        if (input == -1)
        {
            break;
        }
        list.get_data(input);
    }
    cout << list.max << " " << list.min;


    return 0;
}