#include <bits/stdc++.h>

using namespace std;

vector<int> merge(vector<int>& v1, vector<int>& v2)
{
    vector<int> arr;
    int i = 0;
    int j = 0;
    int m = v1.size() - 1;
    int r = v2.size() - 1;


    while (i <= m && j <= r)
    {
        if (v1[i] > v2[j])
        {
            arr.push_back(v1[i++]);
        }
        else
        {
            arr.push_back(v2[j++]);
        }
    }
    while (i <= m)
    {
        arr.push_back(v1[i++]);
    }
    while (j <= r)
    {
        arr.push_back(v2[j++]);
    }

    return arr;
}



int main()
{
    int n1;
    cin >> n1;

    vector<int> arr1(n1);

    for (auto i = 0; i < n1; i++)
    {
        int temp;
        cin >> temp;

        arr1[i] = temp;
    }
    int n2;
    cin >> n2;

    vector<int> arr2(n2);

    for (auto i = 0; i < n2; i++)
    {
        int temp;
        cin >> temp;

        arr2[i] = temp;
    }

    vector<int> ans = merge(arr1, arr2);

    for (const auto& i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}