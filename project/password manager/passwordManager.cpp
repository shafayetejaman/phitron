#include <bits/stdc++.h>

using namespace std;

int MAX = 100000; // max index size

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
    void resize(const int &newSize)
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


    int hash(const string &key)
    {
        int index = 0;
        int hashVal = 31; // A prime number for better distribution
        int power = 1;    // Start power at 1

        for (auto &i : key)
        {
            index = (index + ((i - 'a' + 1) * power) % MAX) % MAX; // Use cumulative power and modulus operator
            power = (power * hashVal) % MAX;                       // Update power for the next iteration
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
    void add(string key, string val)
    {
    }
};

int main()
{

    return 0;
}