#include <bits/stdc++.h>
using namespace std;

class student
{
public:
    char grade;
    int count;
    student(int grade)
    {
        this->grade = grade;
        this->count = 0;
    }
    student()
    {
        this->grade;
        this->count = 0;
    }
};

int main()
{
    student arr[] = {
        student('A'),
        student('A'),
        student('B'),
        student('C'),
        student('A'),
        student('B'),
        student('D'),
    };

    student count[26];

    for (const auto &i : arr)
    {
        int in = i.grade - 'A';
        count[in].count++;
        count[in].grade = i.grade;
    }

    for (const auto &i : count)
    {
        if (i.count != 0)
        {
            for (auto j = 0; j < i.count; j++)
            {
                print(i.grade);
            }
        }
    }

    return 0;
}