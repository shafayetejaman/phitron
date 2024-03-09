#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 1;
const long long INF = 1e18 + 1;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<pii> vp;
typedef vector<string> vs;

vector<vector<long long>> graph(N, vector<long long>(N));
int n, e;

void input()
{
    for (auto i = 1; i < N; i++)
    {
        for (auto j = 1; j < N; j++)
        {
            if (i == j) graph[i][j] = 0;
            else graph[i][j] = INF;
        }
    }

    cin >> n >> e;

    while (e--)
    {
        long long v, u, w;
        cin >> u >> v >> w;

        graph[u][v] = min(graph[u][v], w);
    }
}

int main()
{
    input();

    for (auto k = 1; k < N; k++)
    {
        for (auto u = 1; u < N; u++)
        {
            for (auto v = 1; v < N; v++)
            {
                if (graph[u][k] == INF or graph[k][v] == INF) continue;

                graph[u][v] = min(graph[u][v], graph[u][k] + graph[k][v]);
            }
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        int u, v;
        cin >> u >> v;

        if (graph[u][v] == INF) cout << -1 << endl;
        else
            cout << graph[u][v] << endl;
    }


    return 0;
}