#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        vector<int> v(n);
        int mini = INT_MAX;

        for (auto i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        for (auto i = 0; i < n; i++)
        {
            for (auto j = i+1; j < n; j++)
            {
                mini = min(mini, (v[i] + v[j] + (j+1) - (i+1)));
            }
        }
        cout << mini<<endl;
    }
    return 0;
}
