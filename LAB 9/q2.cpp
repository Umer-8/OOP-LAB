#include<iostream>
using namespace std;

class Car
{
    protected:
    string model;
    int price;

    public:
    virtual void setModel(string Model)
    {
        model=Model;
    }
    virtual void setPrice(int Price)=0;
 
    virtual string getModel()
    {
      
    }
     virtual int getPrice()
    {
        
    }
};
class Color:public Car
{
    public:
    void setModel(string model) override
    {
        Car::setModel(model);
    }
    void setPrice(int Price)override
    {
        price=Price;
    }
    string getModel()override
    {
        return model;
    }
     int getPrice()override
    {
        return price;
    }
};
class Company:public Car
{
    public:
    void setModel(string model) override
    {
        Car::setModel(model);
    }
    void setPrice(int Price)override
    {
        price=Price;
    }
    string getModel()override
    {
       return model;
    }
     int getPrice()override
    {
        return price;
    }
};
int main()
{
    Car *c;
    Color co;
    Company com;

    c=&co;
    c->setModel("Honda");
    c->setPrice(300000);
    cout<<c->getModel()<<endl;
    cout<<c->getPrice()<<endl;

    c=&com;
    c->setModel("Toyota");
    c->setPrice(500000);
    cout<<c->getModel()<<endl;
    cout<<c->getPrice()<<endl;

    return 0;
}
