#include <bits/stdc++.h>
using namespace std;
class student
{
public:
    string name;
    int roll;
    int marks;
};

bool comp(student &a, student &b)
{
    if (a.marks == b.marks)
    {
        return a.roll < b.roll;
    }
    return a.marks < b.marks;
}

int main()
{
    int n;
    cin >> n;
    vector<student> v(n);

    for (auto i = 0; i < n; i++)
    {
        cin >> v[i].name;
        cin >> v[i].roll;
        cin >> v[i].marks;
    }
    cout << endl;
    sort(v.begin(), v.end(), comp);

    for (auto i = 0; i < n; i++)
    {
        cout << v[i].name << " ";
        cout << v[i].roll << " ";
        cout << v[i].marks << endl;
    }

    return 0;
}