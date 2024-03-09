// https://www.codechef.com/problems/DIVISIBLEBY8

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<long long> vll;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<pii> vp;
typedef vector<string> vs;
typedef long double ld;
typedef long long ll;
#define ln '\n'
#define loop(n) for(auto j = 0; j < n; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define div(n, k) (n % k == 0)
#define even(n) (n % 2 == 0)

// const int N = 1e5 + 1;

int diff(string s1, string s2)
{
    int count = 0;

    for (auto i = 0; i < s2.size(); i++)
    {
        if (s1[i] != s2[i]) count++;
    }
    
    return count;
}

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;
    vi v;

    if (n == 1)
    {
        s.back() = '8';
        cout << s << ln;
        return;
    }
    if (n == 2)
    {
        for (int i = 10; i <= 99; i++)
        {
            if (div(i, 8)) v.push_back(i);
        }

        string m = s.substr(n - 2);

        int min_op = INT_MAX;
        int ans;
        for (auto& i : v)
        {
            int op = diff(m, to_string(i));
            if (op < min_op)
            {
                min_op = op;
                ans = i;
            }
        }

        s.replace(n - 2, 2, to_string(ans));

        cout << s << ln;

    }
    else
    {
        for (int i = 100; i <= 999; i++)
        {
            if (div(i, 8)) v.push_back(i);
        }

        string m = s.substr(n - 3);

        int min_op = INT_MAX;
        int ans;
        for (auto& i : v)
        {
            int op = diff(m, to_string(i));
            if (op < min_op)
            {
                min_op = op;
                ans = i;
            }
        }
        

        s.replace(n - 3, 3, to_string(ans));

        cout << s << ln;
    }
}

int main()
{
    fast_cin();
    int t = 1;
    cin >> t;

    loop(t) solve();

    return 0;
}