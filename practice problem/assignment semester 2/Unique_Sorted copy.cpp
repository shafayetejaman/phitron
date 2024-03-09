#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        set<int> s;
        int n;
        cin >> n;
        while (n--)
        {
            int i;
            cin >> i;
            s.insert(i);
        }

        vector<int> v(s.begin(), s.end());
        reverse(v.begin(), v.end());
        for (const auto &i : v)
        {
            cout << i << " ";
        }

        cout << endl;
    }

    return 0;
}