#include <bits/stdc++.h>

using namespace std;
stack<char> &add_to_bottom(stack<char> &st, char val)
{
    stack<char> temp;
    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }
    st.push(val);
    while (!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
    return st;
}
void reverse(stack<char> &st)
{
    // Write your code here
    if (st.empty())
    {
        return;
    }
    char val = st.top();
    st.pop();
    reverse(st);
    add_to_bottom(st, val);
}
bool remove_duplicate(stack<char> &st)
{
    bool flag = false;
    stack<char> temp;
    while (!st.empty())
    {
        char c = st.top();
        st.pop();
        if (!st.empty() && st.top() == c)
        {
            st.pop();
            flag = true;
        }
        else
        {
            temp.push(c);
        }
    }
    reverse(temp);
    st = temp;
    return flag;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        stack<char> st;
        for (auto &i : s)
        {
            if (st.empty())
            {
                st.push(i);
            }
            else if (st.top() == i)
            {
                st.pop();
            }
            else
            {
                /*  Red+Blue = Purple
                    Red+Green = Yellow
                    Blue+Green = Cyan     */
                if (i == 'R')
                {
                    if (st.top() == 'B')
                    {
                        st.pop();
                        st.push('P');
                    }
                    else if (st.top() == 'G')
                    {
                        st.pop();
                        st.push('Y');
                    }
                    else
                    {
                        st.push(i);
                    }
                }
                else if (i == 'B')
                {
                    if (st.top() == 'G')
                    {
                        st.pop();
                        st.push('C');
                    }
                    else if (st.top() == 'R')
                    {
                        st.pop();
                        st.push('P');
                    }
                    else
                    {
                        st.push(i);
                    }
                }
                else if (i == 'G')
                {
                    if (st.top() == 'R')
                    {
                        st.pop();
                        st.push('Y');
                    }
                    else if (st.top() == 'B')
                    {
                        st.pop();
                        st.push('C');
                    }
                    else
                    {
                        st.push(i);
                    }
                }
                else
                {
                    st.push(i);
                }
            }
        }
        while (remove_duplicate(st));

        reverse(st);
        while (!st.empty())
        {
            char c = st.top();
            cout << c;
            st.pop();
        }

        cout << endl;
    }

    return 0;
}