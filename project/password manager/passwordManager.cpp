#include <bits/stdc++.h>

using namespace std;

class Node        // elements for the hashmap
{
public:
    string first;
    string second;
    Node(const string &first, const string &second)
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
class ListNode
{
public:
    Node map;
    ListNode *next;
    ListNode(const string &first, const string &second)
    {
        this->map.first = first;
        this->map.second = second;
        this->next = nullptr;
    }
};
class List
{
public:
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    List(const string &first, const string &second)
    {
        ListNode *newNode = new ListNode(first, second);
        this->head = newNode;
        this->tail = newNode;
    }
    List() {}

    void append(string &first, string &second)
    {
        ListNode *newNode = new ListNode(first, second);
        if (this->head == nullptr)
        {
            this->head = newNode;
            this->tail = newNode;
        }
        else
        {
            this->tail->next = newNode;
            this->tail = this->tail->next;
        }
    }

    int size()
    {
        int count = 0;
        ListNode *ptr = this->head;
        while (ptr != nullptr)
        {
            count++;
            ptr = ptr->next;
        }
        return count;
    }
    void delete_node(int index)
    {
        if (this->head == nullptr)
        {
            cout << "List is empty!\n";
            return;
        }
        ListNode *ptr = this->head;
        ListNode *prev = nullptr;
        if (index == 0)
        {
            this->head = ptr->next;
            delete ptr;
            return;
        }
        else if (index >= this->size() || index < 0)
        {
            cout << "Invalid Index!\n";
            return;
        }
        else if (index == this->size() - 1)
        {
            while (ptr->next != nullptr)
            {
                prev = ptr;
                ptr = ptr->next;
            }
            prev->next = nullptr;
            this->tail = prev;
            delete ptr;
            return;
        }

        while (ptr->next != nullptr && index > 0)
        {
            prev = ptr;
            ptr = ptr->next;
            index--;
        }
        prev->next = ptr->next;
        delete ptr;
    }
    int find(const string &key)
    {
        ListNode *ptr = this->head;
        int index = 0;
        while (ptr != nullptr)
        {
            if (ptr->map.first == key)
            {
                return index;
            }
            index++;
            ptr = ptr->next;
        }
        return -1;
    }
};

class Map
{
public:
    int size;
    Node *arr;
    
    Map() // making the map
    {
        this->size = 100000;
        arr = new Node[this->size];
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
    }

    int hash(const string &key) // generating hash index
    {
        int index = 0;
        int hashVal = 31; // prime number for better distribution
        int power = 1;

        for (auto &i : key)
        {
            index = (index + ((i - 'a' + 1) * power) % this->size) % this->size; // decreasing the index by using mod
            power = (power * hashVal) % this->size;
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
            if (this->arr[index].first == key)
            {
                cout << "The Password already exits!" << endl;
            }
            else
            {
            }
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