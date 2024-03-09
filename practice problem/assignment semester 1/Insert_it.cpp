#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, index;
    cin >> n;
    vector<int> v(n),in;
    for (auto i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cin >> m;
    for (auto i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        in.push_back(val);
    }
    cin >> index;
    v.insert(v.begin() + index, in.begin(), in.end());
    for (auto i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}