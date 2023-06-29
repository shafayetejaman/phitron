#include <bits/stdc++.h>

using namespace std;

int MAX = 100000; // for deducing the index size

class Node // elements for the hashmap
{
public:
    string first;
    string second;
    Node(string &first, string &second)
    {
        this->first = first;
        this->second = second;
    }
    Node() {}
    bool empty()
    {
        return first.empty();
    }
};

class Map
{
public:
    int size;

    Node *arr;
    Map(const int &size) // making the map
    {
        this->size = size;
        arr = new Node[size];
        MAX = size;
    }

    void resize(const int &newSize) // increasing or decreasing the map size
    {
        Node *newNode = new Node[newSize];
        for (auto i = 0; i < this->size; i++)
        {
            newNode[i] = arr[i];
        }
        delete[] arr; // freeing old map
        this->arr = newNode;
        this->size = newSize;
        MAX = this->size;
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

    string &operator[](const string &key)
    {
        int index = hash(key);
        if (this->arr[index].empty()) // if there are no pass-word was saved by the key
        {
            arr[index].first = key;
            return arr[index].second;
        }
        else // if duplicate exits
        {


        }
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