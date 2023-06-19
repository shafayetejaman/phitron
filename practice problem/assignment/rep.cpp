#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++)
    {
        string s;
        string x;
        cin >> s;
        cin >> x;
        int search = 0;
        while (search != -1)
        {
            search = s.find(x, 0);
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