#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->right = nullptr;
        this->left = nullptr;
    }
};

class Tree
{
private:
    int size(Node* ptr)
    {
        if (ptr == nullptr)
            return 0;

        int countLeft = size(ptr->left);
        int countRight = size(ptr->right);
        return countLeft + countRight + 1;
    }
    int size_leaf(Node* ptr)
    {
        if (ptr == nullptr)
            return 0;

        if (ptr->left == nullptr && ptr->right == nullptr)
            return 1;

        int countLeft = size_leaf(ptr->left);
        int countRight = size_leaf(ptr->right);
        return countLeft + countRight;
    }
    void print(Node* ptr)
    {
        if (ptr == nullptr)
            return;

        cout << ptr->data << " ";
        print(ptr->left);
        print(ptr->right);
    }
    int hight(Node* curr, int count)
    {
        if (curr == nullptr)
        {
            return count - 1;
        }
        int left = hight(curr->left, count + 1);
        int right = hight(curr->right, count + 1);
        return max(left, right);
    }
    Node* input(vector<int>& v, int l, int r)
    {
        if (l > r)
            return nullptr;

        int mid = l + (r - l) / 2;
        Node* newNode = new Node(v[mid]);

        Node* left = input(v, l, mid - 1);
        Node* right = input(v, mid + 1, r);
        newNode->left = left;
        newNode->right = right;
        return newNode;
    }

public:
    Node* root;
    Tree()
    {
        this->root = nullptr;
    }
    Tree(int data)
    {
        Node* newNode = new Node(data);
        this->root = newNode;
    }

    void print_preorder()
    {
        print(this->root);
    }
    int size()
    {
        return size(this->root);
    }
    int size_leaf()
    {
        return size_leaf(this->root);
    }
    void print_levels()
    {
        string space;
        int i = this->width();
        while (i--)
        {
            space += "  ";
        }
        queue<pair<Node*, int>> que;
        que.push({root, 1});
        int prevLevel = 0;
        while (!que.empty())
        {
            Node* curr = que.front().first;
            int level = que.front().second;
            que.pop();

            if (prevLevel < level)
            {
                prevLevel = level;
                cout << "\n"
                    << space << curr->data << "  ";
                space.pop_back();
                space.pop_back();
            }
            else
            {
                cout << curr->data << " ";
            }

            if (curr->left)
            {
                que.push({curr->left, level + 1});
            }
            if (curr->right)
            {
                que.push({curr->right, level + 1});
            }
        }
        cout << endl;
    }
    void input()
    {
        int data;
        cin >> data;

        if (data == -1)
            return;

        queue<Node*> que;
        this->root = new Node(data);
        que.push(this->root);

        while (!que.empty())
        {
            Node* curr = que.front();
            que.pop();

            int left, right;
            cin >> left >> right;

            Node* leftNode = nullptr;
            Node* rightNode = nullptr;

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

            if (curr->left != nullptr)
            {
                que.push(curr->left);
            }
            if (curr->right != nullptr)
            {
                que.push(curr->right);
            }
        }
    }
    int hight()
    {
        return hight(this->root, 0);
    }
    void input(vector<int>& v)
    {
        this->root = input(v, 0, v.size() - 1);
    }
    int size_level()
    {
        int size = 0;
        if (!this->root)
        {
            return 0;
        }
        queue<pair<Node*, int>> que;
        que.push({this->root, 1});

        while (!que.empty())
        {
            Node* curr = que.front().first;
            int level = que.front().second;

            que.pop();

            size = max(level, size);

            if (curr->left != nullptr)
            {
                que.push({curr->left, level + 1});
            }
            if (curr->right != nullptr)
            {
                que.push({curr->right, level + 1});
            }
        }
        return size;
    }
    int width()
    {
        int ans = 0;
        if (!this->root)
        {
            return 0;
        }
        vector<vector<int>> v;
        queue<pair<Node*, int>> que;

        que.push({root, 1});
        int prevLevel = 0;
        while (!que.empty())
        {
            Node* curr = que.front().first;
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

            if (curr->left)
            {
                que.push({curr->left, level + 1});
            }
            if (curr->right)
            {
                que.push({curr->right, level + 1});
            }
        }
        for (const auto& i : v)
        {
            ans = max(ans, int(i.size()));
        }
        return ans;
    }
};

int main()
{
    Tree tree;
    vector<int> v = {10, 20, 30, 40, 50, 60, 70, 80};

    tree.input(v);

    tree.print_levels();
    // print(tree.size());
    // print(tree.hight());

    return 0;
}

