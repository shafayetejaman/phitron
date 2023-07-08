#include <bits/stdc++.h>

using namespace std;


int main()
{
    stack<int> st;
    queue<int> que;
    int n, m;
    cin >> n >> m;
    while (n--)
    {
        int i;
        cin >> i;
        st.push(i);
    }
    while (m--)
    {
        int i;
        cin >> i;
        que.push(i);
    }

    bool flag = true;
    if (que.size() != st.size())
    {
        flag = false;
    }
    else
    {
        while (!st.empty())
        {
            if (st.top() != que.front())
            {
                flag = false;
                break;
            }
            st.pop();
            que.pop();
        }
    }
    if (flag)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}