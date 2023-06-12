#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input, s;
    getline(cin, input);
    stringstream ss(input);
    string ans;

    while (ss >> s)
    {
        reverse(s.begin(), s.end());
        ans += (s + " ");
    }
    ans.pop_back();
    cout << ans;

    return 0;
}