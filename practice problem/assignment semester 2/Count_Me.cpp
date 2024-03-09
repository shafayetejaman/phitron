#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string input;
        getline(cin, input);
        stringstream ss(input);
        map<string, int> m;
        string s;
        while (ss >> s)
        {
            m[s]++;
        }
        int maxOccur = INT_MIN;
        for (const auto &i : m)
        {
            maxOccur = max(maxOccur, i.second);
        }
        stringstream ss2(input);
        map<string, int> m2;

        while (ss2 >> s)
        {
            auto it = m.find(s);
            if (it->second == maxOccur)
            {
                m2[s]++;
                if (m2[s] == maxOccur)
                {
                    cout << it->first << " " << it->second << endl;
                    break;
                }
            }
        }
    }

    return 0;
}