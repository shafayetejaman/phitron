#include "my_hederfile.h"

using namespace std;

int main()
{

    return 0;
}

class Solution
{
public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &tar)
    {
        int t = 4;

        while (t--)
        {
            if (mat == tar)
                return true;
            for (auto i = 0; i < mat.size(); i++)
            {
                for (auto j = i; j < mat[0].size(); j++)
                {
                    swap(mat[i][j], mat[j][i]);
                }
            }
            for (auto i = 0; i < mat.size(); i++)
            {
                reverse(mat[i].begin(), mat[i].end());
            }
        }
        return false;
    }
};

class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        vector<int> ans(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {

        unordered_map<int, int> m;
        int count = 0;

        for (auto i = 0; i < nums.size(); i++)
        {
            if (m.find(nums[i]) == m.end())
            {
                m[nums[i]]++;
            }
            else
            {
                count += m[nums[i]];
                m[nums[i]]++;
            }
        }
        return count;
    }
};

class Solution
{
public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
    {
        int count = 0;
        int index;
        if (ruleKey == "type")
        {
            index = 0;
        }
        else if (ruleKey == "color")
        {
            index = 1;
        }
        else
        {
            index = 2;
        }

        for (auto i : items)
        {

            if (i[index] == ruleValue)
                count++;
        }
        return count;
    }
};

class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image)
    {
        for (auto &i : image)
        {
            reverse(i.begin(), i.end());
        }
        for (auto &i : image)
        {
            for (auto &j : i)
            {
                if (j == 0)
                {
                    j = 1;
                }
                else
                {
                    j = 0;
                }
            }
        }
        return image;
    }
};

class Solution
{
public:
    int oddCells(int m, int n, vector<vector<int>> &indices)
    {
        int count = 0;

        vector<vector<int>> v(m, vector<int>(n, 0));

        for (auto &i : indices)
        {
            for (auto j = 0; j < n; j++)
            {
                v[i[0]][j]++;
            }
            for (auto j = 0; j < m; j++)
            {
                v[j][i[1]]++;
            }
        }

        for (auto &i : v)
        {
            for (auto &j : i)
            {
                if (j % 2 == 1)
                    count++;
            }
        }
        return count;
    }
};

class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int sum = 0;
        int row = 0;
        int col = 0;

        while (row < mat.size() && col < mat[0].size())
        {
            sum += mat[row][col];
            row++;
            col++;
        }
        row = 0;
        col = mat[0].size() - 1;
        int mid;
        if (mat.size() % 2 == 1)
        {
            mid = mat.size() / 2;
        }
        else
        {
            mid = mat.size();
        }

        while (row < mat.size() && col >= 0)
        {
            if (row != mid)
            {
                sum += mat[row][col];
            }
            row++;
            col--;
        }
        return sum;
    }
};

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        vector<int> v;
        int count = 0;

        for (auto &i : nums)
        {
            v.push_back(log(i) / log(10) + 1);
        }
        for (auto &i : v)
        {
            if (i % 2 == 0)
                count++;
        }
        return count;
    }
};

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max_s = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            max_s = std::max(max_s, sum);
            if (sum < 0)
            {
                sum = 0;
            }
        }

        return max_s;
    }
};

class Solution
{
public:
    int minCostToMoveChips(vector<int> &position)
    {
        int even = 0;
        int odd = 0;
        for (auto i = 0; i < position.size(); i++)
        {
            if (position[i] % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }

        return std::min(even, odd);
    }
};
class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        vector<int> array(arr.size());
        int maxi = arr.back();
        array.back() = -1;
        for (int i = arr.size() - 2; i >= 0; i--)
        {
            maxi = max(maxi, array[i + 1]);
            array[i] = maxi;
        }
        return array;
    }
};
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (s.empty() || t.empty())
            return false;
        unordered_map<char, int> m;
        for (auto i = 0; i < t.size(); i++)
        {
            if (m.find(t[i]) == m.end())
                m[t[i]] = i;
        }

        vector<int> in;

        for (const auto &i : s)
        {
            auto it = m.find(i);
            if (it == m.end())
            {
                return false;
            }
            else
            {
                in.push_back(it->second);
            }
        }
        for (auto i = 0; i < in.size()-1; i++)
        {
            if (in[i] > in[i+1])
            {
                return false;
            }
        }
        return true;
    }
};

class Solution
{
public:
    bool isHappy(int n)
    {
        long long sum;
        unordered_map<int, bool> m;
        string arr = to_string(n);
        while (true)
        {
            for (const auto &i : arr)
            {
                sum += pow((i - '0'), 2);
            }
            if (sum == 1)
            {
                return true;
            }
            else if (m.find(sum) == m.end())
            {
                m[sum];
            }
            else
            {
                return false;
            }
            arr = to_string(sum);
        }
        return false;
    }
};