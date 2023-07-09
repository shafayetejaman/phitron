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

            if (ptr->left != nullptr)
            {
                if (ptr->left->data > data)
                {
                    ptr->right = newNode;
                }
                else
                {
                    ptr->left = newNode;
                }
            }
        }
        helper_add(data, ptr->left);
        helper_add(data, ptr->right);
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
    }
};

int main()
{
    Tree tree(10);
    tree.add(20);
    tree.add(25);
    tree.add(30);
    tree.add(35);
    tree.print();

    return 0;
}