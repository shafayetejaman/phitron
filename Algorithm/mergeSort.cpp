#include <bits/stdc++.h>

using namespace std;


vector<int> merge(vector<int>& left, vector<int>& right)
{
    vector<int> ans;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {
            ans.push_back(left[i]);
            i++;
        }
        else
        {
            ans.push_back(right[j]);
            j++;
        }
    }
    while (i < left.size())
    {
        ans.push_back(left[i]);
        i++;
    }
    while (j < right.size())
    {
        ans.push_back(right[j]);
        j++;
    }
    return ans;
}

vector<int> merge_sort(vector<int>& arr)
{
    if (arr.size() <= 1) return arr;

    int mid = arr.size() / 2;

    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    left = merge_sort(left);
    right = merge_sort(right);

    return merge(left, right);
}

void merge(vector<int>& arr, int start, int mid, int end)
{
    vector<int> temp;
    int i = start;
    int j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }
    while (j <= end)
    {
        temp.push_back(arr[j++]);
    }
    for (int i = start, j = 0; i <= end; i++, j++)
    {
        arr[i] = temp[j];
    }
}

void merge_short(vector<int>& arr, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        merge_short(arr, start, mid);
        merge_short(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    vector<int> arr = {7, 7, 8, 1, 4, 2, 3, 6, 0, 5};

    print(merge_sort(arr));

    return 0;
}
