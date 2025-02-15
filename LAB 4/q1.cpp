#include<iostream>
using namespace std;

class Circle
{
private:
double radius;
public:
Circle(double radius)
{
    this->radius=radius;
}
double getarea()
{
    return 3.142*radius*radius;
}
double getperimeter()
{
    return 2*3.142*radius;
}
};
int main()
{
    double radius;

    cout<<"Enter radius of the circle:"<<endl;
    cin>>radius;

    Circle c(radius);    

    cout<<"Area is:" <<c.getarea()<<endl;
    cout<<"Perimeter is :"<<c.getperimeter()<<endl;

    return 0;   
}
