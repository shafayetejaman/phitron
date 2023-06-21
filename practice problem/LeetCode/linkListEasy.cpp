#include "my_hederfile.h"

using namespace std;

int main()
{

    return 0;
}

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *ptr = head;
        if (ptr == nullptr)
        {
            return head;
        }
        while (ptr->next != nullptr)
        {
            if (ptr->val == ptr->next->val)
            {
                ptr->next = ptr->next->next;
            }
            else
            {
                ptr = ptr->next;
            }
        }
        return head;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                ListNode *h = head;
                while (h != slow)
                {
                    h = h->next;
                    slow = slow->next;
                }
                return h;
            }
        }
        return NULL;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head != nullptr)
            reverse(head, nullptr, head);
        return head;
    }
    void reverse(ListNode *&head, ListNode *prev, ListNode *curr)
    {
        if (curr->next == nullptr)
        {
            head = curr;
            head->next = prev;
            return;
        }
        reverse(head, curr, curr->next);
        curr->next = prev;
    }
};
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        int len = size(head);
        
    }
    int size(ListNode *head)
    {
        int count = 0;
        while (head != nullptr)
        {
            count++;
            head = head->next;
        }
        return count;

    }
};