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
        {
            return 1;
        }

        int countLeft = helper_size(ptr->left);
        int countRight = helper_size(ptr->right);
        return countLeft + countRight;
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

    void print()
    {
        helper_print(this->root);
    }
    int size()
    {
        return helper_size(this->root);
    }
};

int main()
{
    Tree tree(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(40);
    Node *e = new Node(90);
    Node *f = new Node(50);
    Node *h = new Node(80);
    Node *g = new Node(60);

    tree.root->left = b;
    tree.root->right = c;
    b->left = d;
    b->right = e;

    e->left = g;

    c->right = f;
    f->right = h;

    tree.print();
    print(tree.size());

    return 0;
}