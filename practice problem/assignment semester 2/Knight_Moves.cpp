#include <bits/stdc++.h>
using namespace std;

int N, M;

typedef pair<int, int> pii;
typedef vector<int> vi;

bool valid(int i, int j)
{
    return i >= 0 and j >= 0 and i < N and j < M;
}

int bfs(int si, int sj, int di, int dj)
{
    if (si == di and sj == dj) return 0;

    vector<pii> dis = {{-1, 2}, {-2, 1}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    vector<vi> lev(N, vi(M, 0));
    vector<vi> vis(N, vi(M, false));

    queue<pii> que;
    que.push({si, sj});
    lev[si][sj] = 0;
    vis[si][sj] = true;

    while (!que.empty())
    {
        int i = que.front().first;
        int j = que.front().second;

        que.pop();
        if (i == di and j == dj) return lev[i][j];

        for (auto& v : dis)
        {
            int ni = i + v.first;
            int nj = j + v.second;

            if (!valid(ni, nj) or vis[ni][nj]) continue;

            que.push({ni, nj});
            lev[ni][nj] = lev[i][j] + 1;
            vis[ni][nj] = true;
        }
    }

    return -1;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int si, sj, di, dj;
        cin >> N >> M >> si >> sj >> di >> dj;

        cout << bfs(si, sj, di, dj) << endl;
    }


    return 0;
}
