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
        int n;
        cin >> n;

        vb dp(n + 1, false);
        dp[n] = true;

        for (auto i = n; i >= 0; i--)
        {
            if (i * 2 <= n and i + 3 <= n)
            {
                dp[i] = dp[i * 2] or dp[i + 3];
            }
            else if (i * 2 <= n)
            {
                dp[i] = dp[i * 2];
            }
            else if (i + 3 <= n)
            {
                dp[i] = dp[i + 3];
            }
        }
        
        if (dp[1])
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}