#include<iostream>
using namespace std;

class Car
{
    public:
     mutable int enginehorsepower;
     mutable int seating_capacity;
     mutable int numspeakers;

    void changeattributes(int x,int y,int z)const
    {
        enginehorsepower=x;
        seating_capacity=y;
        numspeakers=z;
    }
    void displayattributes()
    {
        cout<<"Engine horsepower:"<<enginehorsepower<<endl;
        cout<<"Seating capacity:"<<seating_capacity<<endl;
        cout<<"Number of speakers:"<<numspeakers<<endl;
    }
};
int main()
{
     Car c;
    c.enginehorsepower=540;
    c.seating_capacity=3;
    c.numspeakers=2;
    c.displayattributes();
    c.changeattributes(660,4,3);
    c.displayattributes();
    return 0;
}