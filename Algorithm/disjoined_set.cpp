#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi parent(10);
vi Size(10, 1);

int find(int curr)
{
    if (curr == parent[curr]) return curr;
    return find(parent[curr]);
}

void Union(int i, int j)
{
    int pi = find(i);
    int pj = find(j);

    if (pi == pj) return;

    if (Size[pj] > Size[pi])
    {
        parent[pi] = pj;
        Size[pj] += Size[pi];
    }
    else
    {
        parent[pj] = pi;
        Size[pi] += Size[pj];
    }
}


int main()
{
    iota(parent.begin(), parent.end(), 0);

    Union(7, 4);
    Union(1, 3);
    Union(2, 3);
    Union(4, 5);
    Union(6, 5);

    for (auto i = 1; i < 10; i++)
    {
        cout << i << " : " << find(i) << endl;
    }


    return 0;
}