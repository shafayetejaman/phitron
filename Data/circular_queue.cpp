#include "my_hederfile.h"

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
        if (this->frontIndex >= this->sizeOfArr)
        {
            if (this->backIndex >= this->sizeOfArr)
            {
                int back = backIndex % this->sizeOfArr;
                if (this->backIndex < this->frontIndex)
                {
                    this->arr[back] = data;
                    this->backIndex++;
                }
                else
                {
                    cout << "the queue is full!" << endl;
                }
            }
            else
            {
                if (this->backIndex >= this->frontIndex)
                {
                    this->arr[this->backIndex] = data;
                    this->backIndex++;
                }
                else
                {
                    cout << "the queue is full!" << endl;
                }
            }
        }
        else
        {
            if (this->backIndex >= this->sizeOfArr)
            {
                int back = backIndex % this->sizeOfArr;
                if (this->backIndex < this->frontIndex)
                {
                    this->arr[back] = data;
                    this->backIndex++;
                }
                else
                {
                    cout << "the queue is full!" << endl;
                }
            }
            else
            {
                if (this->backIndex >= this->frontIndex)
                {
                    this->arr[this->backIndex] = data;
                    this->backIndex++;
                }
                else
                {
                    cout << "the queue is full!" << endl;
                }
            }
        }
    }
    int front()
    {
        return this->arr[this->frontIndex];
    }
    int back()
    {
        return this->arr[this->backIndex];
    }
    void print()
    {
        for (auto i = this->frontIndex; i < this->backIndex; i++)
        {
            if (i >= this->sizeOfArr)
            {
                cout << this->arr[i % this->sizeOfArr] << " ";
            }
            else
            {
                cout << this->arr[i] << " ";
            }
        }
        cout << endl;
    }
    int size()
    {
        return this->sizeOfArr;
    }
    void pop()
    {
        this->frontIndex++;
    }
};

int main()
{
    Queue queue(10);

    for (auto i = 0; i < queue.size(); i++)
    {
        queue.push(i);
    }
    queue.pop();
    queue.print();

    return 0;
}