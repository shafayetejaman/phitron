#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 1;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<string> graph;
vector<vector<bool>> vis(N, vector<bool>(N, false));

int n, m;
vector<pii> dis = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool valid(int i, int j)
{
    return i >= 0 and j >= 0 and i < n and j < m and graph[i][j] != '-' and !vis[i][j];
}

int dfs(int i, int j)
{
    vis[i][j] = true;

    int count = 1;

    for (auto& k : dis)
    {
        int ni = i + k.first;
        int nj = j + k.second;

        if (!valid(ni, nj)) continue;
        count += dfs(ni, nj);
    }
    return count;
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
}

int main()
{
    input();
    int count = INT_MAX;

    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < m; j++)
        {
            if (valid(i, j))
            {
                int c = dfs(i, j);
                count = min(count, c);
            }
        }
    }
    if (count == INT_MAX) cout << -1;
    else
        cout << count;

    return 0;
}
