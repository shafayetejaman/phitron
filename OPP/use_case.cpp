#include <iostream>
using namespace std;

//base class
class Vehicle
{
public:
    //function to be overridden by child class
    virtual void soundHorn()
    {
        cout << "The vehicle makes a sound" << endl;
    }
};

//first derived class
class Car: public Vehicle
{
public:
    //overriding soundHorn function
    void soundHorn()
    {
        cout << "The car sounds: Honk Honk" << endl;
    }
};

//second derived class
class Motorcycle: public Vehicle
{
public:
    //overriding soundHorn function
    void soundHorn()
    {
        cout << "The motorcycle sounds: Beep Beep" << endl;
    }
};

int main()
{
    // Creating a pointer to a new object
    Vehicle* v = new Vehicle;
    Vehicle* c = new Car; 
    Vehicle* m = new Motorcycle; 

                    //         Output

    v->soundHorn(); // The vehicle makes a sound  

    c->soundHorn(); // The car sounds : Honk Honk

    m->soundHorn(); // The motorcycle sounds : Beep Beep

    return 0;
}