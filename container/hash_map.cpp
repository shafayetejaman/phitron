#include <bits/stdc++.h>
using namespace std;

template <typename T, typename Y>
class Node
{
public:
    T key;
    Y val;
    Node *next;

    Node(const T &key, const Y &val)
    {
        this->key = key;
        this->val = val;
        this->next = nullptr;
    }
};

template <typename T, typename Y>
class List
{
public:
    Node<T, Y> *head;
    Node<T, Y> *tail;

    List()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    Node<T, Y> *append(const T &key, const Y &val = Y())
    {
        Node<T, Y> *newNode = new Node<T, Y>(key, val);
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

        return newNode;
    }

    Node<T, Y> *find(const T &key)
    {
        Node<T, Y> *temp = this->head;
        while (temp)
        {
            if (temp->key == key)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
    bool erase(const T &key)
    {
        Node<T, Y> *temp = this->head;

        if (temp && temp->key == key)
        {
            this->head = temp->next;
            if (this->tail == temp)
            {
                this->tail = nullptr;
            }
            delete temp;
            return true;
        }
        else
        {
            while (temp->next && temp->next->key != key)
            {
                temp = temp->next;
            }
            if (temp->next && temp->next->key == key && temp->next == this->tail)
            {
                Node<T, Y> *deleteNode = this->tail;
                this->tail = temp;
                tail->next = nullptr;
                delete deleteNode;
                return true;
            }
            else if (temp->next && temp->next->key == key)
            {
                Node<T, Y> *deleteNode = temp->next;
                temp->next = temp->next->next;
                delete deleteNode;
                return true;
            }
        }
        return false;
    }
};

template <typename T, typename Y>
class Map
{
private:
    int lambda;
    int arraySize;
    int elements;
    List<T, Y> *array;

    int hash_val(const T &key, const int Size)
    {
        hash<T> stringHash;
        return abs(int(stringHash(key))) % Size;
    }

public:
    Map(const int lambda = 2, const int arraySize = 2)
    {
        this->lambda = lambda;
        this->arraySize = arraySize;
        this->elements = 0;
        array = new List<T, Y>[this->arraySize];
    }
    Node<T, Y> *find(const T &key)
    {
        int index = hash_val(key, this->arraySize);
        return array[index].find(key);
    }

    Y &operator[](const T &key)
    {
        Node<T, Y> *node = find(key);
        if (node)
        {
            return node->val;
        }
        Node<T, Y> *newNode = array[hash_val(key, this->arraySize)].append(key);
        this->elements++;
        if (this->elements / this->arraySize > this->lambda)
        {
            resize();
        }
        return newNode->val;
    }

    int size()
    {
        return this->elements;
    }

    void erase(const T &key)
    {
        if (this->array[hash_val(key, this->arraySize)].erase(key))
        {
            this->elements--;
        }
        else
        {
            print("not found!");
        }
    }
    void resize(const int size = 0)
    {
        int newLambda = this->lambda * 2;
        int newSize;
        if (size == 0)
            newSize = this->arraySize * 2;
        else
            newSize = size;

        List<T, Y> *newArray = new List<T, Y>[newSize];

        for (auto i = 0; i < this->arraySize; i++)
        {
            List<T, Y> &list = array[i];
            Node<T, Y> *head = list.head;

            while (head)
            {
                int index = hash_val(head->key, newSize);
                Node<T, Y> *newNode = newArray[index].append(head->key);
                newNode->val = head->val;
                head = head->next;
            }
        }
        for (auto i = 0; i < this->arraySize; i++)
        {
            List<T, Y> &list = array[i];

            while (list.head)
            {
                list.erase(list.tail->key);
            }
        }
        print("resized");

        delete[] this->array;
        this->array = newArray;
        this->arraySize = newSize;
        this->lambda = newLambda;
    }
};

int main()
{
    Map<string, int> m;
    print();

    m["akash"] = 12;
    m["sg"] = 12;
    m["su"] = 12;
    m["sgi"] = 12;
    m["sgt"] = 12;
    m["sgw"] = 12;

    print(m.size());

    return 0;
}
