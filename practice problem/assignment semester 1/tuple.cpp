#include <bits/stdc++.h>
using namespace std;

tuple<int,double,string, vector<int>> get_data()
{
    vector<int> v = {1, 2, 3};
    string s = "from data";
    int i = 4;
    double d = 4.5;
    return {i, d, s, v};
}

int main()
{
    auto [i, d, s, v] = get_data();

    print(i);
    print(d);
    print(s);
    print(v);

    return 0;
}