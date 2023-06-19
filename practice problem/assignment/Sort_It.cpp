#include <bits/stdc++.h>

using namespace std;

class Student
{
public:
    string name;
    int cla;
    char section;
    int id;
    int mark_mat;
    int mark_eng;
    int sum;
};

bool com(Student a, Student b)
{
    if (a.sum == b.sum)
    {
        return a.id < b.id;
    }
    return a.sum > b.sum;
}

int main()
{
    int n;
    cin >> n;

    Student arr[n];
    for (auto i = 0; i < n; i++)
    {
        cin >> arr[i].name >> arr[i].cla >> arr[i].section >> arr[i].id >> arr[i].mark_mat >> arr[i].mark_eng;
        arr[i].sum = arr[i].mark_eng + arr[i].mark_mat;
    }

    sort(arr, arr + n, com);

    for (auto i = 0; i < n; i++)
    {
        cout << arr[i].name << ' '
             << arr[i].cla << ' '
             << arr[i].section << ' '
             << arr[i].id << ' '
             << arr[i].mark_mat << ' '
             << arr[i].mark_eng
             << endl;
    }
}