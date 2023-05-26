#include <bits/stdc++.h>

using namespace std;

class Person
{
public:
    char name[50];
    float height;
    int age;

    Person(const char *na, float hei, int ag)
    {
        strcpy(name, na);
        height = hei;
        age = ag;
    }
};

int main()
{
    Person *person1 = new Person("akash", 5.11, 20);
    Person *person2 = new Person("shakib", 5.5, 22);

    if (person1->age > person2->age)
    {
        cout << person1->name;
    }
    else
    {
        cout << person2->name;
    }

    return 0;
}
