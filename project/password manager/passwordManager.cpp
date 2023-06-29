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
class Array
{
public:
    int size;

    Node *arr;
    Array(int size)
    {
        this->size = size;
        arr = new Node[size];
    }
    void resize(int newSize)
    {
        
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