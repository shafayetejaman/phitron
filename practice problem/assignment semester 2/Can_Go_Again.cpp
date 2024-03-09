#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> pii;
typedef vector<long long> vi;

const long long N = 1e3 + 1;
const long long INF = 1e18 + 1;
long long ver, eag;

vector<vector<pair<long long, long long>>> adj_list()
{
    cin >> ver >> eag;
    vector<vector<pair<long long, long long>>> graph(N);

    for (auto i = 0; i < eag; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
    }
    return graph;
}

auto graph = adj_list();
vector<long long> dis(N, INF);

bool bfs(long long st)
{
    for (auto& i : dis)
    {
        i = INF;
    }

    vector<long long> vis(N, false);
    dis[st] = 0;
    long long count = 0;

    while (true)
    {
        long long flag = false;
        for (auto u = 1; u < graph.size(); u++)
        {
            if (graph[u].empty()) continue;

            for (auto& i : graph[u])
            {
                long long w = i.first;
                long long v = i.second;
                if (dis[u] != INF and dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    flag = true;
                }
            }
        }
        if (!flag) return false;
        if (count >= ver - 1) return true;
        count++;
    }
    return false;
}

int main()
{
    long long u, t, v;
    cin >> u >> t;

    bool flag = false;
    vi ans;

    if (bfs(u)) flag = true;

    while (t--)
    {
        cin >> v;
        ans.push_back(dis[v]);
    }

    if (flag)
    {
        cout << "Negative Cycle Detected";
    }
    else
    {
        for (auto& i : ans)
        {
            if (i == INF) cout << "Not Possible" << endl;
            else
                cout << i << endl;
        }

    }

    return 0;
}

