#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_matrix()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    for (auto i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;

        graph[u][v] = w;
        graph[v][u] = w;
    }
    return graph;
}

vector<vector<pair<int, int>>> adj_list()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);

    for (auto i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u - 1].push_back({v, w});
        graph[v - 1].push_back({u, w});
    }
    return graph;
}

int main()
{
    // auto graph = adj_matrix();
    // print();
    // print(graph);

    auto graph = adj_list();

    for (auto i = 0; i < graph.size(); i++)
    {
        cout << (i + 1) << " : ";
        for (const auto& j : graph[i])
        {
            cout << "{" << j.first << "," << j.second << "} ";
        }
        cout << endl;
    }

    return 0;
}
