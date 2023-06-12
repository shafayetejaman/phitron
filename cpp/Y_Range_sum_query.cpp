#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    vector<long long> left(n,0);
    vector<long long> right(n,0);
    long long sum = 0;

    for (auto i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    for (auto i = 1; i < n; i++)
    {
        left[i] = arr[i - 1] + left[i - 1];
    }

    for (auto i = n-2; i >= 0; i--)
    {
        right[i] = arr[i + 1] + right[i + 1];
    }

    while(q--)
    {
        int a, b;
        cin >> a >> b;
        cout << (sum - (left[a-1] + right[b-1])) << endl;
    }

    return 0;
}