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
        ListNode *temp;
        while (head != nullptr)
        {
            if (head->val != val)
            {
                ListNode *newNode = new ListNode(head->val);
                if (newHead == nullptr)
                {
                    newHead = newNode;
                    temp = newHead;
                }
                else
                {
                    temp->next = newNode;
                    temp = temp->next;
                }
            }
            head = head->next;
        }
        return newHead;
    }
};