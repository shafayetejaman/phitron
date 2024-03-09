#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list()
{
    int node, edge;
    cin >> node >> edge;

    vector<vector<int>> graph(node + 1);
    for (auto i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    return graph;
}

auto graph = adj_list();
vector<bool> visited(graph.size(), false);

bool dfs(int u, int p = -1)
{
    visited[u] = true;
    bool ans = false;
    for (const auto& i : graph[u])
    {
        if (p == u) continue;
        if (visited[i]) return true;
        ans = ans or dfs(i, u);
        visited[i] = true;
    }
    return ans;
}

int main()
{
    print(dfs(1));

    return 0;
}