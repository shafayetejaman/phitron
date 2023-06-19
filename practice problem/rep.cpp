#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        string s;
        string x;
        cin >> s;
        cin >> x;
        int search = 0;
        s.replace(search, x.size(), "$");
        while (search != -1)
        {
            search = s.find(x, search);
            if (search == -1)
            {
                break;
            }
            s.replace(search, x.size(), "$");
        }
        cout << s << endl;
    }
    return 0;
}