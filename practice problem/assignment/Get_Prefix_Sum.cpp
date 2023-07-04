#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> v(n), sum(n);  

    for (auto i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sum[0] = v[0];
    for (auto i = 1; i < n; i++)
    {
        sum[i] = sum[i - 1] + v[i];
    }
    reverse(sum.begin(), sum.end());

    for (auto i = 0; i < n; i++)
    {
        cout << sum[i] << " ";
    }

    return 0;
}

