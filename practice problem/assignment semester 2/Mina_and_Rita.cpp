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
        string s1, s2;
        cin >> s1 >> s2;

        int n = s1.size();
        int m = s2.size();

        vvi dp(n + 1, vi(m + 1, 0));

        for (auto i = 1; i <= n; i++)
        {
            for (auto j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int i = n;
        int j = m;
        int count = 0;

        while (i > 0 and j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                i--; j--;
                count++;
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                {
                    i--;
                    count++;
                }
                else
                {
                    j--;
                    count++;
                }
            }
        }

        while (i > 0)
        {
            i--;
            count++;
        }
        while (j > 0)
        {
            j--;
            count++;
        }


        cout << count << endl;
    }


    return 0;
}