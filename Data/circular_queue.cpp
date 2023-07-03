#include "my_hederfile.h"

using namespace std;

class Queue
{
private:
    int size;
    int frontIndex;
    int backIndex;
    vector<int> arr;

public:
    Queue(int size)
    {
        this->size = size;
        this->frontIndex = 0;
        this->backIndex = 0;
        vector<int> arr(size);
        this->arr = arr;
    }

    void push(int data)
    {
        if (this->backIndex == this->size)
        {
            
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
};

int main()
{

    return 0;
}