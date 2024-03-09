#include <bits/stdc++.h>

using namespace std;

int main()
{
    list<string> List;
    string s;
    while (true)
    {
        cin >> s;
        if (s == "end")
        {
            break;
        }
        List.push_back(s);
    }
    // for (const auto &i : List)
    // {
    //     cout << i << endl;

    // }
    int t;
    cin >> t;
    int i = 0;
    while (t--)
    {
        cin >> s;

        if (s == "visit")
        {
            cin >> s;
            int j = 0;
            bool flag = false;
            while (*next(List.begin(), j) != s)
            {
                j++;
                if (j >= List.size())
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                cout << "Not Available" << endl;
            }
            else
            {
                cout << *next(List.begin(), j) << endl;
                i = j;
            }
        }
        else
        {
            bool flag = false;
            if (s[0] == 'p' && i > 0)
            {
                i--;
                flag = true;
            }
            else if (s[0] == 'n' && i < List.size() - 1)
            {
                i++;
                flag = true;
            }
            else if (s[0] == 'p' && i == 0)
            {
                cout << "Not Available" << endl;
            }
            else if (s[0] == 'n' && i == List.size() - 1)
            {
                cout << "Not Available" << endl;
            }
            if (flag)
            {
                if (i >= 0 && i < List.size())
                {
                    cout << *next(List.begin(), i) << endl;
                }
                else
                {
                    cout << "Not Available" << endl;
                }
            }
        }
    }

    return 0;
}