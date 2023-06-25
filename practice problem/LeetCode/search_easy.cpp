#include "my_hederfile.h"

using namespace std;

int main()
{


    return 0;
}

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;
        if (x == 1 || x == 2 || x == 3)
            return 1;
        int mid;
        int l = 4;
        int r = x / 2;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (mid * mid == x)
            {
                return mid;
            }
            if (mid * mid < x)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return r;
    }
};
class Solution
{
public:
    char nextGreatestLetter(vector<char> &lett, char tar)
    {
        int l = 0;
        int r = lett.size() - 1;
        char ans = lett[0];
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (lett[mid] > tar)
            {
                ans = lett[mid];
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return ans;
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
            else if(m.find(sum) == m.end())
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