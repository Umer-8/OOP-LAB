#include<iostream>
using namespace std;

class Shape
{
    protected:
    double Area;

    public:
    Shape(double Area):Area(Area){}
    virtual double getArea()=0;

};
class Rectangle:public Shape
{
    public:
    Rectangle(double Area):Shape(Area){}
     double getArea()override
    {
        return Area;
    }
};
class Triangle:public Shape
{
    public:
    Triangle(double Area):Shape(Area){}
    double getArea()override
   {
       return Area;
   }
};
int main()
{
    Shape *s;
    Rectangle r(13.2);
    Triangle t(10.4);
    s=&r;
    cout<<"Area of Rectangle:"<<s->getArea()<<endl;
    s=&t;
    cout<<"Area of Triangle:"<<s->getArea()<<endl;

    return 0;
}
