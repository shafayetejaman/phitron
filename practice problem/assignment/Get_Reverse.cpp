#include <bits/stdc++.h>

using namespace std;

class Student
{
public:
    string name;
    int cla;
    char section;
    int mark_eng;
    int mark_math;
};

int main()
{
    int n;
    cin >> n;

    Student arr[n];
    for (auto i = 0; i < n; i++)
    {
        cin >> arr[i].name
             >> arr[i].cla
             >> arr[i].section
             >> arr[i].mark_eng
             >> arr[i].mark_math ;
    }
    reverse(arr, arr + n);
    for (auto i = 0; i < n; i++)
    {
        cout << arr[i].name << ' '
             << arr[i].cla << ' '
             << arr[i].section << ' '
             << arr[i].mark_eng << ' '
             << arr[i].mark_math << endl;
    }
}