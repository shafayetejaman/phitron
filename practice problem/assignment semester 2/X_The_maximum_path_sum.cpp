#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<pii> vp;
typedef vector<string> vs;

const int N = 1e2 + 1;

long long sum = LLONG_MIN;
vvi v;
int n, m;

void fun(int i, int j, long long s)
{
    if (i == n - 1 and j == m - 1)
    {
        sum = max(sum, s + v[i][j]);
        return;
    }
    if (i >= n or j >= m) return;

    if (i < n)
    {
        fun(i + 1, j, s + v[i][j]);
    }
    if (j < m)
    {
        fun(i, j + 1, s + v[i][j]);
    }
}

int main()
{
    cin >> n >> m;
    v.resize(n);
    for (auto& i : v)
    {
        i.resize(m);
    }

    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    fun(0, 0, 0);
    cout << sum;

    return 0;
}
