#include <bits/stdc++.h>

using namespace std;

class Student
{
public:
    string name;
    int cla;
    char section;
    int id;
};

int main()
{
    int n;
    cin >> n;

    Student arr[n];
    for (auto i = 0; i < n; i++)
    {
        cin >> arr[i].name >> arr[i].cla >> arr[i].section >> arr[i].id;
    }

    int i = 0, j = n - 1;

    while (i < j)
    {
        swap(arr[i].id, arr[j].id);
        i++;
        j--;
    }

    for (auto i = 0; i < n; i++)
    {
        cout << arr[i].name << ' '
             << arr[i].cla << ' '
             << arr[i].section << ' '
             << arr[i].id
             << endl;
    }
}