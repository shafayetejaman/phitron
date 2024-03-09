#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "ecc ~&aaddbb  e";
    string ans;

    int count[26 * 2] = {0};
    for (const auto &i : s)
    {
        if (!isalpha(i))
            continue;
        if (i >= 'a' && i <= 'z')
            count[i - 'a']++;
        else
            count[i - 'A' + 26]++;
    }

    for (auto i = 0; i < 26; i++)
    {
        if (!count[i])
            continue;
        while (count[i]--)
        ans += char(i + 'a');
    }
    for (auto i = 26; i < 26 * 2; i++)
    {
        if (!count[i])
            continue;
        while (count[i]--)
        ans += char(i - 26 + 'A');
    }
    cout << ans << endl;

    return 0;
}