#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 1;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<string> graph;
vector<vector<bool>> vis(N, vector<bool>(N, false));

int n, m, si, sj, ei, ej;
vector<pii> dis = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool valid(int i, int j)
{
    return i >= 0 and j >= 0 and i < n and j < m and graph[i][j] != '-' and !vis[i][j];
}

bool dfs(int i, int j)
{
    vis[i][j] = true;
    bool c = false;

    if (i == ei and j == ej) return true;

    for (auto& k : dis)
    {
        int ni = i + k.first;
        int nj = j + k.second;

        if (!valid(ni, nj)) continue;
        c = c or dfs(ni, nj);
    }
    return c;
}

void input()
{
    cin >> n >> m;

    for (auto i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        graph.push_back(s);
    }

    cin >> si >> sj >> ei >> ej;
}

int main()
{
    input();
    
    if (dfs(si, sj)) cout << "YES";
    else cout << "NO";

    return 0;
}
