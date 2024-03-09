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
    }
    return graph;
}

auto graph = adj_list();

int dfs(int u, vector<bool>& vis)
{
    vis[u] = true;

    int count = 1;
    for (const auto& i : graph[u])
    {
        if (vis[i]) continue;
        count += dfs(i, vis);
    }
    return count;
}

int main()
{
    int level;
    cin >> level;
    vector<bool> vis(N, false);

    cout << dfs(level, vis) - 1;

    return 0;
}
