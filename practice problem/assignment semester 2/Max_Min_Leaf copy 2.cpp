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

int main()
{
    Node *root;
    input(root);
    int max = INT_MIN;
    int min = INT_MAX;
    MaxMin(root, min, max);
    cout << max << " " << min;

    return 0;
}