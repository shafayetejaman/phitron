#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

vector<vector<int>> adj_list()
{
    int ver, eag;
    cin >> ver >> eag;
    vector<vector<int>> graph(N);

    for (auto i = 0; i < eag; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    return graph;
}

auto graph = adj_list();
int path;
vector<int> vis(N, false);

void dfs(int u, int tar, int count = 0)
{
    vis[u] = true;

    if (u == tar)
    {
        path = min(path, count);
    }

    for (const auto& i : graph[u])
    {
        if (vis[i]) continue;
        dfs(i, tar, count + 1);
    }
    vis[u] = false;
}

int find(int st, int tar)
{
    fill(vis.begin(), vis.end(), false);
    path = INT_MAX;
    dfs(st, tar);

    if (path == INT_MAX) return -1;
    return path;
}

int main()
{
    int qr;
    cin >> qr;

    while (qr--)
    {
        int st, tar;
        cin >> st >> tar;
        cout << find(st, tar) << endl;
    }

    return 0;
}