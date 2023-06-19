#include <bits/stdc++.h>

using namespace std;

int main()
{
    string re = "EGYPT";
    string input;
    getline(cin, input);

    int i = input.find(re);
    while (i != -1)
    {
        input.replace(i, re.size(), " ");
        i = input.find(re);
    }
    cout << input;

    return 0;
}