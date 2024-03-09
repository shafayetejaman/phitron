#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        stack<char> st;
        for (auto &i : s)
        {
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                if (i == 'A')
                {
                    if (st.top() == 'B')
                    {
                        st.pop();
                    }
                    else
                    {
                        st.push(i);
                    }
                }
                else
                {
                    if (st.top() == 'A')
                    {
                        st.pop();
                    }
                    else
                    {
                        st.push(i);
                    }
                }
            }
        }
        if (st.empty())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;

        }
    }

    return 0;
}