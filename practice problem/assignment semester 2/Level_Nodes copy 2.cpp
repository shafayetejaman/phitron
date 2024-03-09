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
vector<int> reverseLevelOrder(Node *&root)
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return {};
    }
    root = new Node(data);

    vector<vector<int>> v;
    queue<pair<Node *, int>> que;
    v.push_back({});
    que.push({root, 1});
    int prevLevel = 1;
    while (!que.empty())
    {
        Node *curr = que.front().first;
        int level = que.front().second;
        que.pop();

        if (prevLevel < level)
        {
            prevLevel = level;
            v.push_back({curr->data});
        }
        else
        {
            v.back().push_back(curr->data);
        }

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
            que.push({curr->left, level + 1});
        }
        if (curr->right)
        {
            que.push({curr->right, level + 1});
        }
    }
    int printLevel;
    cin >> printLevel;
    if (printLevel < 0 || printLevel >= v.size())
    {
        return {};
    }

    return {v[printLevel]};
}

int main()
{
    Node *root;

    vector<int> v = reverseLevelOrder(root);
    if (!v.empty())
    {
        for (const auto &i : v)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << "Invalid";
    }

    return 0;
}