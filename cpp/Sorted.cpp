#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (auto i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        bool flag = true;
        for (auto i = 0; i < n-1; i++)
        {
            if(arr[i] > arr[i+1])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }


    }


    return 0;
}