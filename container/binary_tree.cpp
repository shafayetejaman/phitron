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


    void print()
    {
        helper_print(this->root);
    }
};

int main()
{
    Tree tree(10);
        Node *b = new Node(20);
        Node *c = new Node(20);
        Node *d = new Node(20);
        Node *e = new Node(20);
        Node *f = new Node(20);


    tree.print();

    return 0;
}