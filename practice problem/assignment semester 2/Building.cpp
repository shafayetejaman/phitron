#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<pii> vp;
typedef vector<string> vs;

vi parent(N);
vi Size(N, 1);

int find(int u)
{
    if (u == parent[u]) return u;
    else return find(parent[u]);
}

void Union(int u, int v)
{

    if (Size[u] > Size[v])
    {
        parent[v] = u;
        Size[u] += Size[v];
    }
    else
    {
        parent[u] = v;
        Size[v] += Size[u];
    }
}

class edge
{
public:
    int u, v, w;

    edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool cmp(edge& a, edge& b)
{
    return a.w < b.w;
}

int main()
{
    for (auto i = 1; i < N; i++)
    {
        parent[i] = i;
    }

    int n, e;
    cin >> n >> e;

    vector<edge> list;

    while (e--)
    {
        int  u, v, w;
        cin >> u >> v >> w;

        list.push_back(edge(u, v, w));
    }

    sort(list.begin(), list.end(), cmp);

    long long sum = 0;

    for (auto& i : list)
    {
        int u = find(i.u);
        int v = find(i.v);

        if (u == v) continue;

        Union(u, v);
        sum += i.w;
    }

    bool flag = false;

    for (auto i = 1; i < n; i++)
    {
        int u = find(i);
        int v = find(i + 1);

        if (u != v)
        {
            flag = true;
            break;
        }
    }

    if (flag) cout << -1;
    else cout << sum;

    return 0;
}
