#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, w;
    getline(cin, s);
    cin >> w;
    int it = 0, count = 0;
    while (it < s.size())
    {
        if (it != 0)
            it += w.size();

        it = s.find(w, it);

        if (it == -1)
            break;

        count++;
    }
    print(count);

    return 0;
}