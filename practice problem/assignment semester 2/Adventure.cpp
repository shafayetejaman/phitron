#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<pii> vp;
typedef vector<string> vs;

const int N = 1e5 + 1;

int main()
{
    int t;
    cin >> t;
    
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        vp v(n);
        for (auto i = 0; i < n; i++)
        {
            cin >> v[i].first; // w
        }
        for (auto i = 0; i < n; i++)
        {
            cin >> v[i].second; // v
        }

        vvi dp(v.size() + 1, vi(w + 1, 0));

        for (auto i = 1; i <= n; i++)
        {
            for (auto j = 1; j <= w; j++)
            {
                if (v[i - 1].first <= j)
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1].first] + v[i - 1].second);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        cout << dp[n][w] << endl;
    }

    return 0;
}