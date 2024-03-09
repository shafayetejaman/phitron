#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& v, int l, int m, int r)
{
    vector<int> arr;
    int i = l;
    int j = m + 1;

    while (i <= m && j <= r)
    {
        if (v[i] > v[j])
        {
            arr.push_back(v[i++]);
        }
        else
        {
            arr.push_back(v[j++]);
        }
    }
    while (i <= m)
    {
        arr.push_back(v[i++]);
    }
    while (j <= r)
    {
        arr.push_back(v[j++]);
    }

    for (auto i = l; i <= r; i++)
    {
        v[i] = arr[i - l];
    }
}

void merge_sort(vector<int>& v, int l, int r)
{
    if (l >= r) return;

    int mid = l + (r - l) / 2;

    merge_sort(v, l, mid);
    merge_sort(v, mid + 1, r);

    merge(v, l, mid, r);
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
    
    merge_sort(arr, 0, arr.size() - 1);

    for (const auto &i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}