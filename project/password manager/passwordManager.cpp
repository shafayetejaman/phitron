#include <bits/stdc++.h>

using namespace std;

class Node // elements for the hashmap
{
public:
    string first, second;

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
    ListNode(const string &first)
    {
        this->map.first = first;
        this->next = nullptr;
    }
};

class List // for duplicate password key
{
public:
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    int size = 0;

    List(const string &first, const string &second)
    {
        ListNode *newNode = new ListNode(first, second);

        this->head = newNode;
        this->tail = newNode;
    }
    List() {}

    bool empty()
    {
        if (this->size == 0)
        {
            return true;
        }
        return false;
    }

    string &append(const string &first)
    {
        ListNode *newNode = new ListNode(first);
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
        this->size++;
        return newNode->map.second;
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
            this->size--;
            return;
        }
        else if (index >= this->size || index < 0)
        {
            cout << "Invalid Index!\n";
            return;
        }
        else if (index == this->size - 1)
        {
            while (ptr->next != nullptr)
            {
                prev = ptr;
                ptr = ptr->next;
            }

            prev->next = nullptr;
            this->tail = prev;

            delete ptr;
            this->size--;
            return;
        }

        while (ptr->next != nullptr && index > 0)
        {
            prev = ptr;
            ptr = ptr->next;
            index--;
        }
        prev->next = ptr->next;
        this->size--;
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
    void print()
    {
        for (auto i = this->head; i != nullptr; i = i->next)
        {
            cout << i->map.first << " : " << i->map.second << endl;
        }
    }
};

class Map
{
private:
    bool isempty = true;

public:
    int size;
    Node *arr;
    List list;

    Map() // making the map
    {
        this->size = 1000000;
        arr = new Node[this->size];
    }

    void resize(const int &newSize) // increasing or decreasing the map size
    {
        Node *newNode = new Node[newSize];
        if (newNode == nullptr)
        {
            cout << "Failed to resize the array!" << endl;
            return;
        }
        for (auto i = 0; i < this->size; i++)
        {
            newNode[i] = arr[i];
        }
        delete[] arr; // freeing old map
        this->arr = newNode;
        this->size = newSize;
    }
    void print()
    {
        for (auto i = 0; i < this->size; i++)
        {
            if (!this->arr[i].empty())
            {
                cout << this->arr[i].first << " : " << this->arr[i].second << endl;
            }
        }
    }
    int hash(const string &key) // generating hash index
    {
        int index = 0;
        int hashVal = 31; // prime number for better distribution
        int power = 1;

        for (auto &i : key)
        {
            if (isdigit(i))
            {
                index = (index + ((i - '0' + 1) * power) % this->size) % this->size; // decreasing the index by using mod
            }
            else
            {
                index = (index + ((i - 'a' + 1) * power) % this->size) % this->size;
            }

            power = (power * hashVal) % this->size;
        }
        return index;
    }

    string &operator[](const string &key)
    {
        int index = hash(key);
        if (this->arr[index].empty()) // if there are no password was saved by the key
        {
            arr[index].first = key;
            this->isempty = false;
        }
        else // inserting new password in the list
        {
            return this->list.append(key);
        }

        return arr[index].second;
    }

    bool find(const string &key)
    {
        int index = hash(key);
        int pos = this->list.find(key);
        if (pos != -1 || this->arr[index].first == key)
        {
            cout << "The Password already exits!" << endl;
            return true;
        }
        return false;
    }

    bool empty()
    {
        return this->isempty;
    }
};

class PassWord
{
private:
    string loginPass;
    Map arr;

public:
    PassWord(const string &loginPass)
    {
        this->loginPass = loginPass;
    }
    void add(const string &key, const string &pass)
    {
        if (!arr.find(key))
        {
            arr[key] = pass;
        }
    }
    void print()
    {
        if (!arr.empty())
        {
            arr.print();
        }
        if (!arr.list.empty())
        {
            arr.list.print();
        }
        else
        {
            cout << "No password has been saved!";
        }
    }
};

int main()
{
    string loginPass;
    cout << "\nType the password to login to the Password Manager.\n-> ";
    cin >> loginPass;

    PassWord passWord(loginPass);
    int t = 2;

    while (t--)
    {
        string key, pass;
        cout << "Name : ";
        cin >> key;
        cout << "Password : ";
        cin >> pass;

        passWord.add(key, pass);
    }
    passWord.print();

    return 0;
}