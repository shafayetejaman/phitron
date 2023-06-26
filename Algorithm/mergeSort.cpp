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
vector<int> merge_sort(vector<int> arr)
{
    if (arr.size() == 1)
    {
        return arr;
    }
    int mid = arr.size() / 2;
    
    vector<int> left = merge_sort({arr.begin(), arr.begin() + mid});

    vector<int> right = merge_sort({arr.begin() + mid, arr.end()});

    return merge(left, right);
}

int main()
{
    vector<int> arr = {1, 4, 2, 3, 6, 0, 5};

   vector<int> ans =  merge_sort(arr);
   print(ans);

   return 0;
}