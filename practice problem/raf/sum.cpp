#include <bits/stdc++.h>

using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    vector<long long> sum(N);
    sum[0] = v[0];
    for (int i = 1; i < N; i++)
    {
        sum[i] = v[i] + sum[i - 1];
    }

    reverse(sum.begin(), sum.end());

    for (int X : sum)
    {
        cout << X << " ";
    }
    return 0;
}