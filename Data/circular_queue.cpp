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
};

int main()
{
    Queue queue(10);
    for (auto i = 0; i < queue.size()-1; i++)
    {
        queue.push(i);
    }
    queue.print();

    return 0;
}