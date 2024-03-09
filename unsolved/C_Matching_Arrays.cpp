// https://codeforces.com/contest/1896/problem/C

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<long long, long long> pll;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
#define loop(n) for(auto j = 0; j < (n); j++)
#define even(n) ((n) % 2 == 0)
#define odd(n) ((n) % 2 != 0)
#define LL (long long)
#define LD (long double)
#define ll long long
#define ln '\n'
#define all(x) (x).begin(), (x).end()

const int N = 4e5 + 1;
// const int M = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(N, -1);

    vll a(n);

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        arr[temp] = i;
        a[i] = temp;
    }

    vll b(n);

    for (auto& i : b)
    {
        cin >> i;
    }

    vll ans(n);
    set<int> s;

    sort(all(b), greater<>());
    int count = 0;

    for (int i = N - 1; i >= 1; i--)
    {
        if (count >= k) break;

        if (arr[i] != -1)
        {
            ans[arr[i]] = b.back();
            b.pop_back();
            s.insert(arr[i]);
            count++;
        }

    }

    for (int i = 0; i < n; i++)
    {
        if (!s.count(i))
        {
            ans[i] = b.back();
            b.pop_back();
        }
    }

    count = 0;

    for (auto i = 0; i < n; i++)
    {
        if (a[i] > ans[i]) count++;
    }

    if (count != k)
    {
        cout << "NO" << ln;
        return;
    }

    cout << "YES" << ln;

    for (auto& i : ans)
    {
        cout << i << " ";
    }

    cout << ln;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--) solve();

    return 0;
}