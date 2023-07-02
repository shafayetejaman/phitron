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
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *first = head;
        ListNode *temp = head;
        ListNode *last = head;

        int count = 1;
        while (count != k)
        {
            count++;
            first = first->next;
        }
        int size = 0;
        while (temp != nullptr)
        {
            size++;
            temp = temp->next;
        }
        size = size - k;

        while (last != nullptr && size != 0)
        {
            last = last->next;
            size--;
        }
        swap(last->val, first->val);
        return head;
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
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *head2 = head;
        ListNode *newHead = nullptr;
        ListNode *temp;
        int sum = 0;
        while (head2 != nullptr)
        {
            if (head2->val == 0 && head2 != head)
            {
                ListNode *newNode = new ListNode(sum);
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
                sum = 0;
            }
            sum += head2->val;
            head2 = head2->next;
        }
        return newHead;
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
        {
            return list2;
        }
        else if (list2 == nullptr)
        {
            return list1;
        }
        ListNode *ans;
        if (list1->val < list2->val)
        {
            ListNode *newNode = new ListNode(list1->val);
            ans = newNode;
            list1 = list1->next;
        }
        else
        {
            ListNode *newNode = new ListNode(list2->val);
            ans = newNode;
            list2 = list2->next;
        }
        ListNode *curr = ans;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                ListNode *newNode = new ListNode(list1->val);
                curr->next = newNode;
                curr = curr->next;
                list1 = list1->next;
            }
            else
            {
                ListNode *newNode = new ListNode(list2->val);
                curr->next = newNode;
                curr = curr->next;
                list2 = list2->next;
            }
        }
        while (list1 != nullptr)
        {

            ListNode *newNode = new ListNode(list1->val);
            curr->next = newNode;
            curr = curr->next;
            list1 = list1->next;
        }
        while (list2 != nullptr)
        {
            ListNode *newNode = new ListNode(list2->val);
            curr->next = newNode;
            curr = curr->next;
            list2 = list2->next;
        }
        return ans;
    }
};

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        return merge_sort(head);
    }
    ListNode *merge_sort(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *midElement = mid(head);

        ListNode *right = merge_sort(midElement);

        ListNode *left = merge_sort(head);

        return merge(left, right);
    }
    ListNode *merge(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
        {
            return list2;
        }
        else if (list2 == nullptr)
        {
            return list1;
        }
        ListNode *ans;
        if (list1->val < list2->val)
        {
            ListNode *newNode = new ListNode(list1->val);
            ans = newNode;
            list1 = list1->next;
        }
        else
        {
            ListNode *newNode = new ListNode(list2->val);
            ans = newNode;
            list2 = list2->next;
        }
        ListNode *curr = ans;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                ListNode *newNode = new ListNode(list1->val);
                curr->next = newNode;
                curr = curr->next;
                list1 = list1->next;
            }
            else
            {
                ListNode *newNode = new ListNode(list2->val);
                curr->next = newNode;
                curr = curr->next;
                list2 = list2->next;
            }
        }
        while (list1 != nullptr)
        {

            ListNode *newNode = new ListNode(list1->val);
            curr->next = newNode;
            curr = curr->next;
            list1 = list1->next;
        }
        while (list2 != nullptr)
        {
            ListNode *newNode = new ListNode(list2->val);
            curr->next = newNode;
            curr = curr->next;
            list2 = list2->next;
        }
        return ans;
    }
    ListNode *mid(ListNode *slow)
    {
        bool flag = true;
        ListNode *fast = slow;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            if (flag)
            {
                flag = false;
                continue;
            }
            slow = slow->next;
        }
        ListNode *mid = slow->next;
        slow->next = nullptr;

        return mid;
    }
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
        ListNode *prevPrev = nullptr;
        ListNode *next = head;
        while (--left)
        {
            prevPrev = prev;
            prev = prev->next;
        }
        while (--right)
        {
            next = next->next;
        }
        if (prevPrev != nullptr)
        {
            prevPrev->next = nullptr;
        }
        ListNode *r_head = prev;
        ListNode *r_tail = next;
        ListNode *lastNext = next->next;
        r_tail->next = nullptr;
        reverse(r_head, nullptr, r_head, r_tail);
        r_tail->next = lastNext;

        if (prevPrev == nullptr)
        {
            return r_head;
        }
        else
        {
            prevPrev->next = r_head;
            return head;
        }
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

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return;

        ListNode *mid = this->mid(head);
        this->reverse(mid, nullptr, mid);

        ListNode *h1 = head;
        ListNode *h2 = mid;

        while (h1 != nullptr && h2 != nullptr)
        {
            ListNode *temp = h1->next;
            h1->next = h2;
            h1 = temp;

            ListNode *temp2 = h2->next;
            h2->next = h1;
            h2 = temp2;
        }

        if (h1 != nullptr)
            h1->next = nullptr;
    }
    ListNode *mid(ListNode *slow)
    {
        bool flag = true;
        ListNode *fast = slow;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            if (flag)
            {
                flag = false;
                continue;
            }
            slow = slow->next;
        }
        ListNode *mid = slow->next;

        return mid;
    }
    void reverse(ListNode *&head, ListNode *prev, ListNode *curr)
    {
        if (curr == nullptr)
        {
            head = prev;
            return;
        }
        reverse(head, curr, curr->next);
        curr->next = prev;
    }
};

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k == 1)
        {
            return head;
        }
        bool flag = true;
        ListNode *curr = head;
        ListNode *r_head = head;
        ListNode *prev = nullptr;
        ListNode *ans = nullptr;
        while (curr != nullptr)
        {
            int index = k;

            while (--index)
            {
                curr = curr->next;
                if (curr == nullptr)
                {
                    return ans;
                }
            }
            ListNode *r_next = curr->next;

            curr->next = nullptr;
            reverse(r_head, nullptr, r_head, curr);
            curr->next = r_next;

            if (prev != nullptr)
            {
                prev->next = r_head;
            }
            if (flag)
            {
                flag = false;
                ans = r_head;
            }
            prev = curr;
            r_head = curr->next;
            curr = r_head;
        }
        return ans;
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