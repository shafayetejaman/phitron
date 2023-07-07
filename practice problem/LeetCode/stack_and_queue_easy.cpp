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

int ans(stack<int> &stk1, stack<int> &stk2, stack<int> &stk3, int sum1, int sum2, int sum3)
{
    if (sum1 == sum2 && sum2 == sum3)
    {
        return sum1;
    }
    int returnAns1 = INT_MIN;
    int returnAns2 = INT_MIN;
    int returnAns3 = INT_MIN;

    if (!stk1.empty())
    {
        int temp = stk1.top();
        stk1.pop();
        returnAns1 = ans(stk1, stk2, stk3, sum1 - temp, sum2, sum3);
        stk1.push(temp);
    }

    if (!stk2.empty())
    {
        int temp = stk2.top();
        stk2.pop();
        returnAns2 = ans(stk1, stk2, stk3, sum1, sum2 - temp, sum3);
        stk2.push(temp);
    }

    if (!stk3.empty())
    {
        int temp = stk3.top();
        stk3.pop();
        returnAns3 = ans(stk1, stk2, stk3, sum1, sum2, sum3 - temp);
        stk3.push(temp);
    }

    return max(returnAns1, max(returnAns2, returnAns3));
}
int ans(stack<int> &stk1, stack<int> &stk2, stack<int> &stk3, int sum1, int sum2, int sum3)
{
    while (true)
    {
        if (sum1 == sum2 && sum2 == sum3)
        {
            return sum1;
        }
        if (sum1 >= sum2 && sum1 >= sum3)
        {
            sum1 -= stk1.top();
            stk1.pop();
        }
        else if (sum2 >= sum1 && sum2 >= sum3)
        {
            sum2 -= stk2.top();
            stk2.pop();
        }
        else
        {
            sum3 -= stk3.top();
            stk3.pop();
        }
    }

    return sum1;
}
int get_sum(stack<int> st)
{
    int sum = 0;
    while (!st.empty())
    {
        sum += st.top();
        st.pop();
    }
    return sum;
}
int maxSum(stack<int> &stk1, stack<int> &stk2, stack<int> &stk3)
{
    // Write your code here
    int sum1 = get_sum(stk1);
    int sum2 = get_sum(stk2);
    int sum3 = get_sum(stk3);

    return ans(stk1, stk2, stk3, sum1, sum2, sum3);
}
