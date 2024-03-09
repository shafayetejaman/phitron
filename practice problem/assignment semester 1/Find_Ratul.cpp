#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    stringstream ss(s);
    bool flag = false;
    while (ss >> s)
    {
        if (s == "Ratul")
        {
            flag = true;
            break;
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