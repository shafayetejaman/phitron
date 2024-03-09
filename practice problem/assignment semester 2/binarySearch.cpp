#include <bits/stdc++.h>

using namespace std;

int fun(vector<int>& v, int l, int r, int tar)
{
    if (l > r)
    {
        return -1;
    }
    int mid = l + (r - l) / 2;
    if (v[mid] == tar)
    {
        return mid;
    }
    if (v[mid] > tar)
    {
        return fun(v, l, mid - 1, tar);
    }
    return fun(v, mid + 1, r, tar);

}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (auto i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        arr[i] = temp;
    }

    int tar;
    cin >> tar;

    int idx = fun(arr, 0, arr.size() - 1, tar);

    if (idx == -1)
    {
        cout << "Not Found\n";
    }
    else
    {
        cout << idx << endl;
    }

    return 0;
}