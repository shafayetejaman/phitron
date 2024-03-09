#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int roll;
    float GPA;
    Student(string name, int roll, float GPA)
    {
        this->name = name;
        this->roll = roll;
        this->GPA = GPA;
    }
};

Student input()
{
    string name;
    int roll;
    float GPA;
    cout << "name : ";
    cin >> name;
    cout << "roll : ";
    cin >> roll;
    cout << "GPA : ";
    cin >> GPA;
    cout << endl;
    Student s(name, roll, GPA);
    return s;
}
class cmp
{
public:
    bool operator()(Student &a, Student &b)
    {
        return a.GPA > b.GPA;
    }
};

int main()
{
    priority_queue<Student, vector<Student>, cmp> pq;
    int n = 3;
    while (n--)
        pq.push(input());
    while (!pq.empty())
    {
        cout << pq.top().name << endl
             << pq.top().GPA << endl
             << pq.top().roll << endl
             << endl;
        pq.pop();
    }

    return 0;
}
// priority_queue<int, vector<int>, greater<int>> pq;
// pq.push(20);
// pq.push(10);
// pq.push(3);
// pq.push(7);
// while (!pq.empty())
// {
//     cout << pq.top() << endl;
//     pq.pop();
// }