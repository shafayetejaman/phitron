#include <bits/stdc++.h>
using namespace std;

int Size = 1e5 + 1;
vector<vector<int>> adj_list(Size);
vector<bool> visited(Size);
vector<int> level(Size, -1);

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        for (int v : adj_list[temp])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
                level[v] = level[temp] + 1;
            }
        }
    }
}

int main()
{
    int N, E;
    cin >> N >> E;

    for (int i = 0; i < E; ++i)
    {
        int A, B;
        cin >> A >> B;
        adj_list[A].push_back(B);
        adj_list[B].push_back(A);
    }

    int L;
    cin >> L;

    bfs(0);

    bool flag = 1;
    int i = 0;
    while (i != Size)
    {
        if (L == level[i])
        {
            cout << i << " ";
            flag = 0;
        }
        i++;
    }
    if (flag)
        cout << -1;

    return 0;
}