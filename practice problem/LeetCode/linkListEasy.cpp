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
            ListNode *temp = ptr->next;
            if (ptr->val == ptr->next->val)
            {
                ptr->next = ptr->next->next;
                delete temp;
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
        ListNode *newList = nullptr;
        ListNode *curr = head;
        ListNode *tail = nullptr;

        while (curr != nullptr)
        {
            append(newList, curr->val, tail);
            curr = curr->next;
        }
        if (head != nullptr)
            reverse(head, nullptr, head);
        curr = head;
        while (curr != nullptr)
        {
            if (curr->val != newList->val)
            {
                return false;
            }
            newList = newList->next;
            curr = curr->next;
        }
        return true;
    }
    void append(ListNode *&head, int val, ListNode *&tail)
    {
        ListNode *newNode = new ListNode(val);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
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
    void deleteNode(ListNode *node)
    {
        ListNode *ptr = node;
        ListNode *temp = nullptr;
        ListNode *temp2 = nullptr;

        while (ptr->next != nullptr)
        {
            ptr->val = ptr->next->val;
            ptr = ptr->next;
            if (ptr->next->next == nullptr)
            {
                temp = ptr->next;
                temp2 = ptr;
            }
        }
        temp2->next = nullptr;
        delete temp;
    }
};
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *newHead = nullptr;
        ListNode *temp = newHead;
        while (head != nullptr)
        {
            if (head->val != val)
            {
                temp->val = head->val;
                temp = temp->next;
            }

        }
        return newHead;
    }
};