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
vector<int> cost(N);
vector<int> dp(N, -1);

int fun(int n)
{
    if (n == 1) return 0;
    if (dp[n] != -1) return dp[n];

    if (n == 2) return dp[n] = abs(cost[n] - cost[n - 1]);

    int ch1 = fun(n - 1) + abs(cost[n] - cost[n - 1]);
    int ch2 = fun(n - 2) + abs(cost[n] - cost[n - 2]);

    return dp[n] = min(ch1, ch2);
}

int main()
{
    int n;
    cin >> n;

    for (auto i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }
    cout << fun(n);


    return 0;
}