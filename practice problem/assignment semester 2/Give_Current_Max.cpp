#include <bits/stdc++.h>

using namespace std;

class Student
{
public:
    string name;
    int roll;
    int marks;
    Student(string name, int roll, int marks)
    {
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};

Student input()
{
    string name;
    int roll;
    int marks;

    cin >> name >> roll >> marks;

    Student s(name, roll, marks);
    return s;
}
void output(const Student &s)
{
    cout << s.name << " " << s.roll << " " << s.marks << endl;
}
class cmp
{
public:
    bool operator()(Student &a, Student &b)
    {
        if (a.marks == b.marks)
            return a.roll > b.roll;

        return a.marks < b.marks;
    }
};

int main()
{
    priority_queue<Student, vector<Student>, cmp> pq;

    int n;
    cin >> n;
    while (n--)
    {
        Student s = input();
        pq.push(s);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int query;
        cin >> query;
        if (query == 0)
        {
            Student s = input();
            pq.push(s);
            output(pq.top());
        }
        else if (query == 1)
        {
            if (!pq.empty())
                output(pq.top());
            else
                cout << "Empty" << endl;
        }
        else
        {

            if (!pq.empty())
                pq.pop();

            if (!pq.empty())
                output(pq.top());
            else
                cout << "Empty" << endl;
        }
    }
    return 0;
}