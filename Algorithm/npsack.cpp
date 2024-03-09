#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main()
{
    int n, cap;
    cin >> n >> cap;

    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    vector<vi> dp(n + 1, vi(cap + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int w = 1; w <= cap; ++w)
        {
            if (w >= arr[i].first)
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - arr[i].first] + arr[i].second);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }


    cout << dp[n][cap] << "\n";

    return 0;
}