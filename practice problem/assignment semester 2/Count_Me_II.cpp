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

        vector<int> v(n);
        for (auto i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            v[i] = num;
        }

        map<int, int> m;
        for (const auto &i : v)
        {
            m[i]++;
        }

        int maxOccur = INT_MIN;
        for (const auto &i : m)
        {
            maxOccur = max(maxOccur, i.second);
        }
        int ans = INT_MIN;
        for (const auto &i : m)
        {
            if (i.second == maxOccur)
            {
                ans = max(i.first, ans);
            }
        }
        cout << ans << " " << m[ans] << endl;
    }

    return 0;
}