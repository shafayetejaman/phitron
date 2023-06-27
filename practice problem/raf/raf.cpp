#include "my_hederfile.h"

using namespace std;


struct ListNode {
    int val;
    ListNode *next = nullptr;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
        {
            return head;
        }
        ListNode *prev = head;
        ListNode *prevPrev = nullptr; // 1 2 3 3 4   left 2 right 4
        ListNode *last = head;
        while (--left)
        {
            prevPrev = prev;
            prev = prev->next;
        }
        while (--right)
        {
            last = last->next;
        }
        if (prevPrev != nullptr)
            prevPrev->next = nullptr;

        ListNode *r_head = prev;
        ListNode *r_tail = last;
        r_tail->next = nullptr;
        reverse(r_head, nullptr, r_head, r_tail);

        r_tail->next = last->next;

        if (prevPrev == nullptr)
        {
            return r_head;
        }
        else
        {
            prevPrev->next = r_head;
            return head;
        }
        return head;
    }
    void reverse(ListNode *&head, ListNode *prev, ListNode *curr, ListNode *&tail)
    {
        if (curr == nullptr)
        {
            tail = head;
            head = prev;
            return;
        }
        reverse(head, curr, curr->next, tail);
        curr->next = prev;
    }
    void append(int val)
    {
        ListNode *newNode = new ListNode(val);
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
        ListNode *ptr = this->head;
        cout << "head -> ";
        while (ptr != nullptr)
        {
            cout << ptr->val << " -> ";
            ptr = ptr->next;
        }
        cout << "null" << endl;
        cout << "tail -> " << tail->val << endl;
    }
};
int main()
{
    Solution list;
    int t = 3;
    while (t--)
    {
        int val;
        cin >> val;
        list.append(val);
    }
    list.reverseBetween(list.head, 1, 3);
    list.print();

    return 0;
}