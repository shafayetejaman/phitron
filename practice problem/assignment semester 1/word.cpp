#include <bits/stdc++.h>
using namespace std;

int main()
{
    stringstream ss("i am a good boy");

    stack<string> st;
    string s;
    while (ss >> s)
    {
        st.push(s);
    }
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }


    return 0;
}