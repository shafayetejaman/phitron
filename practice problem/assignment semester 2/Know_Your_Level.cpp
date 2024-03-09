#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
int st = 0;

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
vector<int> ans;

void bfs(int l)
{
    vector<bool> vis(N, false);
    vector<int> level(N, 0);

    queue<int> que;
    vis[st] = true;
    level[st] = 0;
    que.push(st);

    while (!que.empty())
    {
        int curr = que.front();
        que.pop();
        
        if (l == level[curr]) ans.push_back(curr);

        if (l < level[curr]) return;

        for (const auto& i : graph[curr])
        {
            if (vis[i]) continue;

            que.push(i);
            level[i] = level[curr] + 1;
            vis[i] = true;
        }
    }
}

int main()
{
    int level;
    cin >> level;
    bfs(level);
    sort(ans.begin(), ans.end());

    if (ans.empty())
    {
        cout << -1;
    }
    else
    {
        for (const auto& i : ans)
        {
            cout << i << " ";
        }
    }


    return 0;
}
