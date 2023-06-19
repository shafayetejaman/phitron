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

node *make_list()
{
    node *head = nullptr;

    int val;
    while (true)
    {
        if (val == -1)
        {
            break;
        }
        cin >> val;
        node *newNode = new node(val);

    }




}


int main()
{




    return 0;
}