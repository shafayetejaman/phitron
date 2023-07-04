#include <bits/stdc++.h>

using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    vector<long long> pre(N);
    pre[0] = A[0];
    for (int i = 1; i < N; i++)
    {
        pre[i] = A[i] + pre[i - 1];
    }

    reverse(pre.begin(), pre.end());

    for (int X : pre)
    {
        cout << X << " ";
    }
    return 0;
}