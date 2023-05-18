#include "my_hederfile.h"

using namespace std;

class node
{
public:
    int val;
    node *next;
    int count;
    node(int val)
    {
        this->val = val;
        this->next = nullptr;
        count = 1;
    }
    node &append(int val)
    {
        node *p = this;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        node *new_node = new node(val);
        new_node->next = nullptr;
        p->next = new_node;
        this->count++;

        return *this;
    }
    node &print()
    {
        node *p = this;
        while (p != nullptr)
        {
            cout << p->val << " ";

            p = p->next;
        }
        cout << endl;
        return *this;
    }
    void reverse(node *&head)
    {
        node *curr = head->next;
        node *prev = head;
        while (curr != nullptr)
        {
            node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        prev->count = head->count;
        head->next = nullptr;
        head = prev;
    }
    void reverse(node *&head, node *&curr, node *&prev)
    {
        if (curr == nullptr)
        {
            prev->count = head->count;
            head->next = nullptr;
            head = prev;
            return;
        }
        node *next = curr->next;
        curr->next = prev;
        reverse(head, next, curr);
    }
};

int main()
{
    node *head = new node(1);

    head->append(2);
    head->append(3);
    node *curr = head->next;
    node *prev = head;
    head->reverse(head, curr, prev);

    head->print();
    cout << head->count;

    return 0;
}