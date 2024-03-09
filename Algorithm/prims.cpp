#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
typedef pair<int, int> pii;
typedef vector<int> vi;

class edge
{
public:
    int u;
    int v;
    int w;
    edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
class cmp
{
public:
    bool operator () (edge& a, edge& b)
    {
        return a.w > b.w;
    }
};

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
vi vis(N, false);
vector<edge> edgeList;



void bfs(int st)
{
    priority_queue<edge, vector<edge>, cmp> pq;

    pq.push(edge(st, st, 0));

    while (!pq.empty())
    {
        int u = pq.top().u;
        int v = pq.top().v;
        int w = pq.top().w;

        pq.pop();
        if (vis[v]) continue;
        vis[v] = true;
        edgeList.push_back(edge(u, v, w));

        for (auto& i : graph[u])
        {
            if (vis[i.second]) continue;

            pq.push(edge(v, i.second, i.first));
        }

    }
    edgeList.erase(edgeList.begin());
    for (auto& i : edgeList)
    {
        cout << i.u << "  " << i.v << "  " << i.w << endl;
    }
}


int main()
{
    bfs(1);

    return 0;
}
