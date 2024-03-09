#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
void input(Node *&root)
{
    int data;
    cin >> data;

    if (data == -1)
        return;

    queue<Node *> que;
    root = new Node(data);
    que.push(root);

    while (!que.empty())
    {
        Node *curr = que.front();
        que.pop();

        int left, right;
        cin >> left >> right;

        Node *leftNode = nullptr;
        Node *rightNode = nullptr;

        if (left != -1)
        {
            leftNode = new Node(left);
        }
        if (right != -1)
        {
            rightNode = new Node(right);
        }
        curr->left = leftNode;
        curr->right = rightNode;

        if (curr->left)
        {
            que.push(curr->left);
        }
        if (curr->right)
        {
            que.push(curr->right);
        }
    }
}
bool is_perfect(Node *curr)
{
    if (!curr)
    {
        return true;
    }
    if ((!curr->left && curr->right) || (curr->left && !curr->right) )
    {
        return false;
    }

    bool left = is_perfect(curr->left);
    bool right = is_perfect(curr->right);
    return left && right;
}
int main()
{
    Node *root;
    input(root);
    if (is_perfect(root))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}