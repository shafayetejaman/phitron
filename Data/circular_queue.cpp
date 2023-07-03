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
    queue.pop();
    for (auto i = 0; i < 2; i++)
    {
        queue.push(i);
    }
    queue.print();

    return 0;
}