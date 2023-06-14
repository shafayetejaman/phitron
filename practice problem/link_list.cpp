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
    void reverse_l(node *&head)
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
    node *reverse(node *&head)
    {
        static int count = head->count;
        if (head == nullptr || head->next == nullptr)
        {
            head->count = count;
            return head;
        }
        node *new_head = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }
};

int main()
{
    node *head = new node(1);

    head->append(2);
    head->append(3);
    head->append(4);

    head = head->reverse(head);

    head->print();
    print(head->count);

    return 0;
}