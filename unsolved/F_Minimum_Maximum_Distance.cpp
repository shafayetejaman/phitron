// https://codeforces.com/contest/1881/problem/F

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<long long> vll;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<pii> vp;
typedef vector<string> vs;
typedef long double ld;
typedef long long ll;
#define ln '\n'
#define loop(n) for(auto j = 0; j < n; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define div(n, k) (n % k == 0)
#define even(n) (n % 2 == 0)

// const int N = 1e5 + 1;

vvi adj_list(int n, int m)
{
    vvi graph(n + 1);

    for (auto i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
    }
    return graph;
}
int n, k;

void bfs(int st, int ds, vvi& graph)
{
    vector<int> vis(n + 1, false);
    vector<int> dis(n + 1, INT_MAX);
    
}


void solve()
{
    cin >> n >> k;

    vi v(k);

    for (auto& i : v)
    {
        cin >> i;
    }
    auto graph = adj_list(n, n - 1);




}

int main()
{
    fast_cin();
    int t = 1;
    cin >> t;

    loop(t) solve();

    return 0;
}