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
    void add(int data)
    {
        helper_add(data, this->root);
    }
    void helper_add(int data, Node *ptr)
    {
        if (ptr->left == nullptr || ptr->right == nullptr)
        {
            Node *newNode = new Node(data);

            if (ptr->left == nullptr)
            {
                ptr->left = newNode;
            }
            else
            {
                ptr->right = newNode;
            }
            return;
        }
        helper_add(data, ptr->left);
        helper_add(data, ptr->right);
    }
    // binary insertion
    void insert(int data)
    {
        helper_insert( data, nullptr, this->root);
    }
    void helper_insert(int data, Node *prev, Node *curr)
    {
        if (curr == nullptr)
        {
            Node *newNode = new Node(data);

            if (prev == nullptr)
            {
                // The tree is empty, so make the new node the root
                root = newNode;
            }
            else if (data > prev->data)
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
        helper_print(ptr->left);
        helper_print(ptr->right);
        cout << ptr->data << " ";
    }
};

int main()
{
    Tree tree(10);
    tree.insert(20);
    tree.insert(25);
    tree.insert(30);
    tree.insert(35);
    tree.print();

    return 0;
}