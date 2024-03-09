#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<pii> vp;
typedef vector<string> vs;

const int INF = INT_MAX - 1;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, tar;
        cin >> n >> tar;

        int s = 1000 - tar;

        vvi dp(n + 1, vi(s + 1, INF));
        dp[0][0] = 0;

        vi v(n);
        for (auto& i : v)
        {
            cin >> i;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                if (v[i - 1] <= j)
                {
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - v[i - 1]]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        if (dp[n][s] == INF) cout << -1 << endl;
        else cout << dp[n][s] << endl;
    }


    return 0;
}
