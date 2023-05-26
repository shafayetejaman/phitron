#include <bits/stdc++.h>

using namespace std;

int main()
{
    char c,q;
    int a, b, d;

    cin >> a >> c >> b >>q>> d;
    if (c == '+')
    {
        if ((a + b )== d)
        {
            cout << "Yes";
        }
        else
        {
            cout << (a + b);
        }
    }
    else if (c == '-')
    {
        if ((a - b) == d)
        {
            cout << "Yes";
        }
        else
        {
            cout << (a - b);
        }
    }
    else if (c == '*')
    {
        if ((a * b) == d)
        {
            cout << "Yes";
        }
        else
        {
            cout << (a * b);
        }
    }

    return 0;
}
