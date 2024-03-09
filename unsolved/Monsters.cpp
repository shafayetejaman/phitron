// 

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

const int N = 1e6 + 1;
// const int M = 1e9 + 7;

bool is_prime[N];

void sieve()
{
    memset(is_prime, true, sizeof(is_prime));

    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p * p <= N; p++)
    {
        if (is_prime[p])
        {
            for (int i = p * p; i <= N; i += p)
            {
                is_prime[i] = false;
            }
        }
    }
}


void solve()
{
    ll n;
    cin >> n;

    ll count = 0;
    ll a = 1;
    sieve();

    while (n > 0)
    {
        for (int i = n; i >= 0; i--)
        {
            if (a < i) break;

            if (is_prime[i])
            {
                n -= i;
                count++;
                break;
            }
        }

        n -= a;
        a *= 2;

        count++;
    }

    if (n == 0) count << count << ln;
    else cout << -1 << ln;


    // cout << ln;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--) solve();

    return 0;
}