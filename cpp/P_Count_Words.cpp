#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input,s;
    getline(cin, input);
    stringstream ss(input);
    int count = 0;
    while (ss >> s)
    {
        bool flag = true;
        for (auto i = 0; i < s.size(); i++)
        {
            if (flag)
            {
                if (isalpha(s[i]))
                {
                    count++;
                    flag = false;
                }
            }
            if (s[i]=='!'|| s[i]=='.'|| s[i]=='?' ||s[i]==',')
            {
                flag = true;
            }
        }
    }
    cout << count;
    return 0;
}