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
    bool helper_find(int data, Node *curr)
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
            return helper_find(data, curr->right);
        }
        else
        {
            return helper_find(data, curr->left);
        }
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
    // binary insertion
    void insert(int data)
    {
        helper_insert(data, nullptr, this->root);
    }
    bool find(int data)
    {
        return helper_find(data, this->root);
    }

    void print()
    {
        helper_print(this->root);
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
    print(tree.find(20));
  

    return 0;
}