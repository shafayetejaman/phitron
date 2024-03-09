#include <iostream>
#include <string>
#include <limits.h>
#include <algorithm>

using namespace std;

int is_di(long long num)
{
    int count = 0;
    while (num != 0)
    {
        if ((num & 1) == 0)
        {
            count++;
        }
        else
        {
            break;
        }
        num = num >> 1;
    }
    return count;
}

int main()
{
    int t,ans = INT_MIN;
    cin >> t;
    for (auto i = 0; i < t; i++)
    {
        long long a;
        cin >> a;
        ans = max(ans, is_di(a));
    }
    cout << ans;

    return 0;
}