#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int sizeOfArr;
    int frontIndex;
    int backIndex;
    vector<int> arr;

public:
    Queue(int sizeOfArr)
    {
        this->sizeOfArr = sizeOfArr;
        this->frontIndex = 0;
        this->backIndex = 0;
        vector<int> arr(sizeOfArr);
        this->arr = arr;
    }

    void push(int data)
    {
        int front = frontIndex % this->sizeOfArr;
        int back = backIndex % this->sizeOfArr;

        if ((backIndex - frontIndex) < this->sizeOfArr)
        {

            this->arr[back] = data;
            this->backIndex++;
        }
        else
        {
            cout << "the queue is full!" << endl;
        }
    }
    int front()
    {
        return this->arr[this->frontIndex % this->sizeOfArr];
    }
    int back()
    {
        return this->arr[this->backIndex % this->sizeOfArr];
    }
    void print()
    {
        for (auto i = this->frontIndex; i < this->backIndex; i++)
        {
            cout << this->arr[i % this->sizeOfArr] << " ";
        }
        cout << endl;
    }
    int size()
    {
        return (backIndex - frontIndex);
    }
    int capacity()
    {
        return this->sizeOfArr;
    }
    void pop()
    {
        if (!this->empty())
        {
            this->frontIndex++;
        }
        else
        {
            cout << "the queue is empty!" << endl;
        }
    }
    bool empty()
    {
        if (this->frontIndex < this->backIndex)
        {
            return false;
        }
        return true;
    }
};

int main()
{
    Queue queue(10);

    for (auto i = 0; i < queue.capacity(); i++)
    {
        queue.push(i);
    }
    queue.pop();
    queue.pop();
    for (auto i = 0; i < 3; i++)
    {
        queue.push(i);
    }
    queue.print();
    cout << queue.empty();

    return 0;
}