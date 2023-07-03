#include "my_hederfile.h"

using namespace std;

int main()
{

    return 0;
}

class MyStack
{
public:
    queue<int> q1;
    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        queue<int> q2;
        int topVal;
        while (!q1.empty())
        {
            if (q1.size() != 1)
            {
                q2.push(q1.front());
            }
            else
            {
                topVal = q1.front();
            }

            q1.pop();
        }
        q1 = q2;
        return topVal;
    }

    int top()
    {
        return q1.back();
    }

    bool empty()
    {
        return q1.empty();
    }
};
class MyQueue
{
public:
    MyQueue()
    {
    }

    void push(int x)
    {
    }

    int pop()
    {
    }

    int peek()
    {
    }

    bool empty()
    {
    }
};
