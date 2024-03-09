#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5 + 1;
int ver, eag;

vector<vector<pii>> adj_list()
{
    cin >> ver >> eag;
    vector<vector<pii>> graph(N);

    for (auto i = 0; i < eag; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
    }
    return graph;
}

auto graph = adj_list();
vector<int> vis(N, false);
vector<int> dis(N, INT_MAX);

void bfs(int st)
{
    dis[st] = 0;

    for (auto n = 0; n < ver - 1; n++)
    {
        bool flag = false;
        for (auto u = st; u < graph.size(); u++)
        {
            if (graph[u].empty()) continue;

            for (const auto &i : graph[u])
            {
                int w = i.first;
                int v = i.second;
                if (dis[u] != INT_MAX and dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    flag = true;
                }
            }
        }
        if (!flag) return;
    }
}

int main()
{
    bfs(1);
    for (auto i = 1; i <= 4; i++)
    {
        cout << i << " : " << dis[i] << endl;
    }

    return 0;
}

