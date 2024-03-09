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
        int n, m;
        cin >> n >> m;
        
        int sum = 1000 - m;

        vvb dp(n + 1, vb(sum + 1, false));
        dp[0][0] = true;
       

        vi v(n);

        for (auto& i : v)
        {
            cin >> i;
        }

        for (auto i = 1; i <= n; i++)
        {
            for (auto j = 0; j <= sum; j++)
            {
                if (v[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j] or dp[i][j - v[i - 1]];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        if (dp[n][sum]) cout << "YES\n";
        else cout << "NO\n";
    }


    return 0;
}