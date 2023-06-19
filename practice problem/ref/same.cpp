#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
int print(Node *head)
{
    int cnt = 0;
    Node *tem = head;
    while (tem != NULL)
    {
        cnt++;
        cout << tem->val << " ";
        tem = tem->next;
    }
    return cnt;
}
void insert(Node *&head, int v)
{
    Node *newnode = new Node(v);
    if (head == NULL)
    {
        head = newnode;
        return;
    }

    Node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newnode;
}
// void check(Node *head,int cn)
// {
//     Node *tem=head;
//     Node *newnode=head;
//     int n=cn/2;
//     for(int i=0;i<n;i++)
//     {
//         tem=tem->next;
//     }
//     while(tem!=NULL)
//     {
//         if(newnode->val!=tem-val)
//             cout<<"NO";
//             newnode=newnode->next;
//             tem=tem->next;
//         break;

//     }
// }
int main()
{
    int val;
    Node *head = NULL;
    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        insert(head, val);
    }
    cout << endl;
    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        insert(head, val);
    }
    int cn = print(head);
    if (cn % 2 == 1)
    {
        cout << "NO";
    }
    else if (cn % 2 == 0)
    {
        // check(head,cn);
    }

    return 0;
}