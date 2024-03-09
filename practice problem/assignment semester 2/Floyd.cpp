#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    int n, m = INT_MIN;
    cin >> n;

    vector<vi> v(n, vi(n));

    for (auto& i : v)
    {
        for (auto& j : i)
        {
            cin >> j;
        }
    }
    
    for (auto& i : v)
    {
        for (auto& j : i)
        {
            if (j == -1)
            {
                j = 1e5;
            }
        }
    }

    for (auto k = 0; k < n; k++)
    {
        for (auto i = 0; i < v.size(); i++)
        {
            for (auto j = 0; j < v[0].size(); j++)
            {
                if (v[i][j] > v[i][k] + v[k][j])
                {
                    v[i][j] = v[i][k] + v[k][j];
                }
            }
        }
    }
    
    for (auto& i : v)
    {
        for (auto& j : i)
        {
            if (j == 1e5) continue;
            m = max(m, j);
        }
    }

    cout << m;

    return 0;
}