#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        int n;
        cin >> n;
        cin.ignore();
        string input;
        int ans = 0;
        map<char, int> m;
        getline(cin, input);
        for (const auto &i : input)
        {
            m[i]++;
        }
        for (const auto &i : m)
        {
            ans += (i.second + 1);
        }

        cout << ans << endl;
    }

    return 0;
}
