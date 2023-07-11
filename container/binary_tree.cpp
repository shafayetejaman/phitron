#include "my_hederfile.h"

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
        this->right = nullptr;
        this->left = nullptr;
    }
};

class Tree
{
private:
    int helper_size(Node *ptr)
    {
        if (ptr == nullptr)
            return 0;

        int countLeft = helper_size(ptr->left);
        int countRight = helper_size(ptr->right);
        return countLeft + countRight + 1;
    }
    int helper_size_leaf(Node *ptr)
    {
        if (ptr == nullptr)
            return 0;

        if (ptr->left == nullptr && ptr->right == nullptr)
            return 1;

        int countLeft = helper_size_leaf(ptr->left);
        int countRight = helper_size_leaf(ptr->right);
        return countLeft + countRight;
    }
    void helper_print(Node *ptr)
    {
        if (ptr == nullptr)
            return;

        cout << ptr->data << " ";
        helper_print(ptr->left);
        helper_print(ptr->right);
    }
    int helper_max_hight(Node *curr, int count)
    {
        if (curr == nullptr)
        {
            return count - 1;
        }
        int left = helper_max_hight(curr->left, count + 1);
        int right = helper_max_hight(curr->right, count + 1);
        return max(left, right);
    }

public:
    Node *root;
    Tree()
    {
        this->root = nullptr;
    }
    Tree(int data)
    {
        Node *newNode = new Node(data);
        this->root = newNode;
    }

    void print_preorder()
    {
        helper_print(this->root);
    }
    int size()
    {
        return helper_size(this->root);
    }
    int size_leaf()
    {
        return helper_size_leaf(this->root);
    }
    void print_levels()
    {
        queue<Node *> que;
        que.push(this->root);
        while (!que.empty())
        {
            Node *curr = que.front();
            que.pop();

            cout << curr->data << " ";

            if (curr->left != nullptr)
            {
                que.push(curr->left);
            }
            if (curr->right != nullptr)
            {
                que.push(curr->right);
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

        queue<Node *> que;
        this->root = new Node(data);
        que.push(this->root);

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
    int max_hight()
    {
        return helper_max_hight(this->root, 0);
    }
};

int main()
{
    Tree tree;

    tree.input();

    tree.print_levels();
    // print(tree.size());
    print(tree.max_hight());
    

        return 0;
}