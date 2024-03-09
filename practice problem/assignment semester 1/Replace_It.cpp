#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t; 

    while (t--)
    {
        string s, x;
        cin >> s >> x;
        int it = 0;
        while (true)
        {
            it = s.find(x, it);
            if (it == -1)
                break;
            s.replace(it,x.size(), "$");
        }
        cout << s;
    }


    return 0;
}