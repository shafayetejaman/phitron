#include <bits/stdc++.h>

using namespace std;

int MAX = 100000; // for deducing the index size

class Node // elements for the hashmap
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
    Map(int &size) // making the map
    {
        this->size = size;
        arr = new Node[size];
    }
    void resize(const int &newSize) // increasing or decreasing the map size
    {
        this->size = newSize;
        Node *newNode = new Node[newSize];
        for (auto i = 0; i < this->size; i++)
        {
            newNode[i] = arr[i];
        }
        delete[] arr; // freeing old map
        this->arr = newNode;
    }

    int hash(const string &key) // generating hash index
    {
        int index = 0;
        int hashVal = 31; // prime number for better distribution
        int power = 1;

        for (auto &i : key)
        {
            index = (index + ((i - 'a' + 1) * power) % MAX) % MAX; // decreasing the index by using mod
            power = (power * hashVal) % MAX;
        }
        return index;
    }

    Node *operator[](const string &key)
    {
    }
};

class PassWord
{
private:
    string loginPass;
    PassWord(const string &loginPass)
    {
        this->loginPass = loginPass;
    }

public:
    void add(string &key, string &val)
    {
    }
};

int main()
{

    return 0;
}