#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    int mins = INT_MAX;
    int j = 1;
    for (auto i = 0; i < n; i++)
    {
        cin >> arr[i];
        mins = min(mins, arr[i]);
        if (j == k)
        {
            cout << mins <<' ';
            j = 0;
            mins = INT_MAX;
        }
        j++;
    }
    if (j != 1)
    cout << mins;

    return 0;
}