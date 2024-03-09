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
    void print(Node* ptr)
    {
        if (ptr == nullptr)
        {
            return;
        }
        cout << ptr->data << " ";
        print(ptr->left);
        print(ptr->right);
    }
    Node* insert(Node* node, int data)
    {
        if (!node)
            return new Node(data);


        if (data > node->data)
        {
            node->right = insert(node->right, data);
        }
        else
        {
            node->left = insert(node->left, data);
        }

        return node;
    }
    bool find(int data, Node* curr)
    {
        if (curr == nullptr)
        {
            return false;
        }
        if (curr->data == data)
        {
            return true;
        }

        if (data > curr->data)
        {
            return find(data, curr->right);
        }
        else
        {
            return find(data, curr->left);
        }
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
    Node* erase(Node* root, int val)
    {
        if (!root)
            return nullptr;

        // if the target is in the left subtree
        if (root->data > val)
        {
            root->left = erase(root->left, val);
        }
        // if the target is in the right subtree
        else if (root->data < val)
        {
            root->right = erase(root->right, val);
        }
        // if value found
        else
        {
            if (!root->left && !root->right)
            {
                delete root;
                return nullptr;
            }
            if (!root->left)
            {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            if (!root->right)
            {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = inorder_successor(root->right);
            root->data = temp->data;
            root->right = erase(root->right, temp->data);
        }
        return root;
    }

    Node* inorder_successor(Node* root)
    {
        while (root->left)
        {
            root = root->left;
        }
        return root;
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
    // binary insertion
    void insert(int data)
    {
        this->root = insert(this->root, data);
    }
    bool find(int data)
    {
        return find(data, this->root);
    }

    void print()
    {
        print(this->root);
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
        sort(v.begin(), v.end());
        this->root = this->input(v, 0, v.size() - 1);
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
    void print_levels()
    {
        string space;
        int i = this->width();
        while (i--)
        {
            space += " ";
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
                    << space << curr->data << " ";
                int i = 2;
                if (space.size() >= i)
                {
                    space.pop_back();
                }
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
    void erase(int val)
    {
        this->root = this->erase(this->root, val);
    }
};

int main()
{
    Tree tree;
    vector<int> v = {10, 15, 20, 25, 30, 34, 33, 2};

    tree.input(v);
    tree.print_levels();
    tree.erase(10);

    tree.print_levels();

    return 0;
}