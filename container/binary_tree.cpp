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
    // binary insertion
    void insert(int data)
    {
        helper_insert(data, nullptr, this->root);
    }
    void helper_insert(int data, Node *prev, Node *curr)
    {
        if (curr == nullptr)
        {
            Node *newNode = new Node(data);

            if (prev == nullptr)
            {
                this->root = newNode;
                return;
            }

            if (data > prev->data)
            {
                prev->right = newNode;
            }
            else
            {
                prev->left = newNode;
            }
            return;
        }

        if (data > curr->data)
        {
            helper_insert(data, curr, curr->right);
        }
        else
        {
            helper_insert(data, curr, curr->left);
        }
    }

    void print()
    {
        helper_print(this->root);
    }
    void helper_print(Node *ptr)
    {
        if (ptr == nullptr)
        {
            return;
        }
        cout << ptr->data << " ";
        helper_print(ptr->left);
        helper_print(ptr->right);
    }
};

int main()
{
    Tree tree(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(30);
    tree.insert(40);
    tree.print();

    return 0;
}