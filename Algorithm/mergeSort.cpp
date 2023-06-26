#include "my_hederfile.h"

using namespace std;

vector<int> merge(vector<int> &left, vector<int> &right)
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
vector<int> merge_sort(vector<int> &arr)
{
    if (arr.size() <= 1)
    {
        return arr;
    }
    int mid = arr.size() / 2;

    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    left = merge_sort(left);
    right = merge_sort(right);

    return merge(left, right);
}

int main()
{
    vector<int> arr = {7, 7, 8, 1, 4, 2, 3, 6, 0, 5};

    print(merge_sort(arr));

    return 0;
}