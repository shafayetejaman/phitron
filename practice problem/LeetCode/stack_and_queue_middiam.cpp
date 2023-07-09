#include "my_hederfile.h"

using namespace std;

int main()
{


    return 0;
}
class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        queue<int> que;
        queue<int> temp;
        for (auto i = 1; i <= n; i++)
        {
            que.push(i);
        }
        while (que.size() != 1)
        {
            int count = k - 1;

            while (count--)
            {
                temp.push(que.front());
                que.pop();
            }
            que.pop();
            add_to_front(que, temp);
        }
        return que.front();
    }
    void add_to_front(queue<int> &que, queue<int> &temp)
    {
        while (!que.empty())
        {
            temp.push(que.front());
            que.pop();
        }
        que = temp;
    }
};