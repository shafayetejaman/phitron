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
vector<bool> vis(N, false);

int dfs(int u)
{
    if (vis[u]) return 0;
    vis[u] = true;

    int count = 1;

    for (const auto& i : graph[u])
    {
        if (vis[i]) continue;
        count += dfs(i);
    }
    return count;
}

vector<int> component()
{
    vector<int> ans;

    for (auto i = 0; i < graph.size(); i++)
    {
        if (graph[i].empty()) continue;
        int count = dfs(i);

        if (count > 1)
            ans.push_back(count);
    }
    sort(ans.begin(), ans.end());

    return  ans;
}

int main()
{
    vector<int> ans = component();

    for (const auto& i : ans)
    {
        cout << i << " ";
    }

    return 0;
}
