#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<pii> ege_list()
{
    int n;
    cin >> n;

    vector<pii> graph;

    while (n--)
    {
        int u, v;
        cin >> u >> v;

        graph.push_back({u, v});
    }
    
    return graph;
}

// bool cmp(pii &a, pii &b)
// {
//     if (a.first == b.first) return a.second < b.second;
//     else return a.first < b.first;

// }

int main()
{
    auto graph = ege_list();

    sort(graph.begin(), graph.end());

    for (auto &i : graph)
    {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}