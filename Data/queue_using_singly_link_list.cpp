#include "my_hederfile.h"

using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class queue
{
public:
    node *front = nullptr;
    node *back = nullptr;
    
};

int main()
{


    return 0;
}