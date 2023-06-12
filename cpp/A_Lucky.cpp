#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore(); 

    while (t--)
    {
        string input, ans;
        getline(cin, input);

        string l = input.substr(0, 3);
        string r = input.substr(input.size() - 3, 3);
        int sum1 = 0, sum2 = 0;
        for (const auto &i : l)
        {
            sum1 += (i - '0');
        }
        for (const auto &i : r)
        {
            sum2 += (i - '0');
        }
        if (sum1 == sum2)
        {
            ans = "YES";
        }
        else
        {
            ans = "NO";
        }

        cout << ans << endl;
    }

    return 0;
}
