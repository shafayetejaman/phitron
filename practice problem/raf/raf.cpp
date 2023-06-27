#include "my_hederfile.h"

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
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
            return head;
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
};
int main()
{
    int n = 10;
        //             9 == 0
    for (auto i = n-1; i > -1; i--)
    {
        cout << i << " ";
    }
    print();

    while (--n)
    {
        print(n);
    }

    return 0;
}