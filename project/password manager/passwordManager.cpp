#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <random>
#include <climits>
#include <limits>

using namespace std;

const int MAX = 20; // maximum length of the password
const int MIN = 8;  // minimum length of the password

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

class List // for handling duplicate hash of keys
{
public:
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    int size = 0;

    List(const string &first, const string &second)
    {
        ListNode *newNode = new ListNode(first, second);
        if (newNode == nullptr)
        {
            cout << "Failed to add password!" << endl;
            return;
        }

        this->head = newNode;
        this->tail = newNode;
    }
    List() {}

    bool empty()
    {
        if (this->size == 0)
            return true;

        return false;
    }

    string &append(const string &first)
    {
        ListNode *newNode = new ListNode(first);
        if (newNode == nullptr)
        {
            cout << "Failed to add password!" << endl;
        }
        else
        {

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
        static string s;
        return s;
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
                return index;

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
public:
    Node *arr;
    List list;
    int size;

    Map() // making the map
    {
        this->size = 1000000;
        arr = new Node[this->size];

        if (arr == nullptr)
        {
            cout << "Failed to add password!" << endl;
            return;
        }
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
            char c;
            if (isdigit(i))
                c = '0';
            else
                c = 'a';

            index = (index + ((i - c + 1) * power) % this->size) % this->size; // decreasing the index by using mod

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
            return true;
        }
        return false;
    }

    int find_index_arr(const string &key)
    {
        int index = hash(key);

        if (this->arr[index].first == key)
        {
            return index;
        }
        return -1;
    }

    bool delete_node(const string &key)
    {
        int pos = this->list.find(key);

        if (pos == -1)
        {
            pos = this->find_index_arr(key);
            if (pos == -1)
            {
                return false;
            }
            else
            {
                this->arr[pos].first.clear();
                this->arr[pos].second.clear();
            }
        }
        else
        {
            this->list.delete_node(pos);
        }
        return true;
    }

    bool empty()
    {
        for (auto i = 0; i < this->size; i++)
        {
            if (!this->arr[i].empty())
            {
                return false;
            }
        }
        return true;
    }
};

// input validation
long long int input(int min, long long int max)
{
    string n;

    while (true)
    {
        cin >> n;

        for (int i = 0; isdigit(n[i]); i++)
        {
            if (i == n.size() - 1)
            {
                long long int num = stoll(n);
                if (num >= min && num <= max)
                    return num;
            }
        }

        cout << "Invalid Input!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Type Again : ";
    }
}

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
        else // asking to overwrite the password
        {
            cout << "The Password already exits!" << endl
                 << "Do you want to overwrite the password?(y,n) : ";
            string choice;
            while (true)
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                getline(cin, choice);
                if (choice.size() == 1 && (tolower(choice[0]) == 'y' || tolower(choice[0]) == 'n'))
                {
                    break;
                }
                cout << "Invalid Input!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Type Again : ";
            }
            if (tolower(choice[0]) == 'y')
            {
                arr[key] = pass; // overwriting the password
            }
        }
    }

    void delete_pass(const string &key)
    {
        if (!this->arr.delete_node(key))
        {
            cout << "The password was not found!" << endl;
        }
    }

    void print()
    {
        bool flag = true;

        if (!arr.empty())
        {
            arr.print();
            flag = false;
        }
        if (!arr.list.empty())
        {
            arr.list.print();
            flag = false;
        }

        if (flag)
        {
            cout << "No password has been saved!" << endl;
        }
    }
    string generate_random_pass()
    {
        string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=";
        string password;
        int len = random();

        // Seed the random number generator


        for (int i = 0; i < len; ++i)
        {
            int randomIndex = random() % characters.size();
            password += characters[randomIndex];
        }

        return password;
    }
    int random()
    {
        static unsigned long long n = 1;
        srand(time(NULL) * n * getpid());
        n++;
        return (rand() % MAX) + MIN;
    }
};

int main()
{
    string loginPass = "24234";
    // cout << "\nType the password to login to the Password Manager.\n-> ";
    // cin >> loginPass;

    PassWord passWord(loginPass);

    string name = "name";
    string pass = "22222";
    passWord.add(name, pass);
    passWord.print();
    passWord.delete_pass(name);
    passWord.print();

    return 0;
}