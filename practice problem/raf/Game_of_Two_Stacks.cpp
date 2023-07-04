#include <bits/stdc++.h>

using namespace std;

int calculate(stack<int> a, stack<int> b, long long maxSum, long long lim, int count)
{
    if (maxSum < lim || a.empty() || b.empty())
    {
        return count - 1;
    }

    int valA = a.top();
    a.pop();
    long long maxSumA = calculate(a, b, maxSum, lim + valA, count + 1);
    a.push(valA);

    int valB = b.top();
    b.pop();
    long long maxSumB = calculate(a, b, maxSum, lim + valB, count + 1);

    return max(maxSumA, maxSumB);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int alen, blen, maxSum;
        cin >> alen >> blen >> maxSum;
        vector<int> av, bv;
        while (alen--)
        {
            int i;
            cin >> i;
            av.push_back(i);
        }
        while (blen--)
        {
            int i;
            cin >> i;
            bv.push_back(i);
        }
        stack<int> a, b;
        while (!av.empty())
        {
            a.push(av.back());
            av.pop_back();
        }
        while (!bv.empty())
        {
            b.push(bv.back());
            bv.pop_back();
        }

        cout << (calculate(a, b, maxSum, 0, 0)) << endl;
    }

    return 0;
}
