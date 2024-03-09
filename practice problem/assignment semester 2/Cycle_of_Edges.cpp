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
int c = 0;

int find(int u)
{
    if (u == parent[u]) return u;
    else return find(parent[u]);
}

void Union(int u, int v)
{
    int pu = find(u);
    int pv = find(v);

    if (pu == pv)
    {
        c++;
        return;
    }

    if (Size[pu] > Size[pv])
    {
        parent[pv] = pu;
        Size[pu] += Size[pv];
    }
    else
    {
        parent[pu] = pv;
        Size[pv] += Size[pu];
    }
}

int main()
{
    for (auto i = 1; i < N; i++)
    {
        parent[i] = i;
    }
    
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int u, v;
        cin >> u >> v;

        Union(u, v);
    }

    cout << c;

    return 0;
}