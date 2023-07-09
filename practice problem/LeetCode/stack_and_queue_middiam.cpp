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
        queue<int> qu;
        queue<int> temp;
        for (auto i = 1; i <= n; i++)
        {
            qu.push(i);
        }
        int count = k-1;
        
        while(count--)
        {
            temp.push(qu.front());
            qu.pop();
        }
    }
};