#include <bits/stdc++.h>
using namespace std;

class student
{
public:
    string name;
    int roll;
    string section;
    double math_marks;
    int cls;

    student(string name, int roll, string section, double math_marks, int cls)
    {
        this->name = name;
        this->math_marks = math_marks;
        this->cls = cls;
        this->roll = roll;
        this->section = section;
    }
};

class cricketer
{
public:
    int jersey_no;
    string country;
};

int main()
{
    student stu[3] = {
        {"al", 1, "a", 4.4, 12},
        {"ab", 2, "a", 3.4, 12},
        {"ac", 3, "a", 4.0, 12},
    };

    int max_num = INT_MIN;
    string ans;

    for (auto &i : stu)
    {
        if (i.math_marks > max_num)
        {
            max_num = i.math_marks;
            ans = i.name;
        }
    }
    print(ans);

    cricketer *kohli = new cricketer;
    cricketer *dhoni = new cricketer;

    kohli->jersey_no = 12;
    kohli->country = "india";

    // dhoni->jersey_no = kohli->jersey_no;
    // dhoni->country = kohli->country;
    *dhoni = *kohli;
    delete kohli;

    print(dhoni->country);
    print(dhoni->jersey_no);
    delete dhoni;

    return 0;
}
