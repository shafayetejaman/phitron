#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    string first;
    string second;
    Node(string first, string second)
    {
        this->first = first;
        this->second = second;
    }
    Node() {}
};
class Map
{
public:
    int size;

    Node *arr;
    Map(int size)
    {
        this->size = size;
        arr = new Node[size];
    }
    void resize(int newSize)
    {
        this->size = newSize;
        Node *newNode = new Node[newSize];
        for (auto i = 0; i < this->size; i++)
        {
            newNode[i] = arr[i];
        }
        delete[] arr;
        this->arr = newNode;
    }
};

int MAX;

class PassWord
{
private:
    string loginPass;
    PassWord(string loginPass)
    {
        this->loginPass = loginPass;
    }

public:
    void add(string key, string val)
    {
    }
};

int main()
{

    return 0;
}