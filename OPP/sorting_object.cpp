#include <bits/stdc++.h>
using namespace std;

class student
{
public:
    string name;
    int roll;
    double gpa;
    student(string name, int roll, double gpa)
    {
        this->gpa = gpa;
        this->name = name;
        this->roll = roll;
    }
};

int main()
{
    student arr[3] = {
        student("akash", 12, 3.3),
        student("batash", 10, 3.9),
        student("magla", 1, 4.9),
    };

   sort(arr, arr + 3, [](student &a, student &b){ return a.roll < b.roll;});
   for (auto i = 0; i < 3; i++)
   {
        print(arr[i].name);
    }
    return 0;
}