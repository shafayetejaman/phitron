#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj_list()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);

    for (auto i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
    }
    return graph;
}

auto graph = adj_list();

vector<bool> visited(graph.size()+1, false);
vector<int> height(graph.size()+1, 0);
vector<int> depth(graph.size()+1, 0);

void dfs(int u)
{
    visited[u] = true;
    for (const auto& v : graph[u])
    {
        if (visited[v]) continue;
        depth[v] = depth[u] + 1;
        dfs(v);
        height[u] = max(height[u], height[v] + 1);
    }
}

void dfs_print(int u)
{
    visited[u] = true;
    cout << u << " : height = " << height[u] << ", depth = " << depth[u] << endl;
    for (const auto& v : graph[u])
    {
        if (visited[v]) continue;
        dfs_print(v);
    }
}

int main()
{

    dfs(1);
    fill(visited.begin(), visited.end(), false);
    dfs_print(1);


    return 0;
}
