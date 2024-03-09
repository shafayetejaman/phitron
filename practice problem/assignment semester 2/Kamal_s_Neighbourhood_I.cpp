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


int main()
{
    int level;
    cin >> level;

    cout << graph[level].size();

    return 0;
}
