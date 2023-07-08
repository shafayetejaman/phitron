#include <bits/stdc++.h>


using namespace std;

long long power(long long x, int n)
{
    long long res = 1;
    while(n--)
        res *= x;
    return res;
}

long long calculateSum(int x, int n)
{
    long long sum = 0;
    for (int i = 2; i <= n; i += 2)
        sum += power(x, i);
    return sum;
}

int main()
{
    long long x, n;
    cin >> x >> n;
    cout << calculateSum(x, n);
    return 0;
}
