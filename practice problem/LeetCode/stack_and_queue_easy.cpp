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

    bool empty()
    {
        return q1.empty();
    }
};
class MyQueue
{
public:
    stack<int> q1;
    MyQueue()
    {
    }

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        stack<int> q2;
        int topVal;
        while (!q1.empty())
        {
            if (q1.size() != 1)
            {
                q2.push(q1.top());
            }
            else
            {
                topVal = q1.top();
            }

            q1.pop();
        }

        while (!q2.empty())
        {

            q1.push(q2.top());

            q2.pop();
        }

        return topVal;
    }
    int peek()
    {
        stack<int> q2;
        int topVal;
        while (!q1.empty())
        {

            q2.push(q1.top());
            if (q1.size() == 1)
            {
                topVal = q1.top();
            }

            q1.pop();
        }

        while (!q2.empty())
        {

            q1.push(q2.top());

            q2.pop();
        }
        return topVal;
    }

    int top()
    {
        stack<int> q2;

        while (!q1.empty())
        {
            q2.push(q1.top());
            q1.pop();
        }
        q1 = q2;
        return q2.top();
    }

    bool empty()
    {
        return q1.empty();
    }
};
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> st, tt;
        for (auto i = 0; i < s.size(); i++)
        {
            if (s[i] != '#')
            {
                st.push(s[i]);
            }
            else
            {
                if (!st.empty())
                    st.pop();
            }
        }
        for (auto i = 0; i < t.size(); i++)
        {
            if (t[i] != '#')
            {
                tt.push(t[i]);
            }
            else
            {
                if (!tt.empty())
                tt.pop();
            }
        }
        if (st.size() != tt.size())
        {
            return false;
        }
        while (!st.empty())
        {
            if (st.top() != tt.top())
            {
                return false;
            }
            st.pop();
            tt.pop();
        }
        return true;
    }
};
int maxSum(stack<int> &stk1, stack<int> &stk2, stack<int> &stk3)
{
    // Write your code here
    stack<int> temp;
    int sum1 = 0, sum2 = 0, sum3 = 0;
    while (!stk1.empty())
    {
        temp.push(stk1.top());
        sum1 += temp.top();
        stk1.pop();
    }
    while (!temp.empty())
    {
        stk1.push(temp.top());

        temp.pop();
    }
}