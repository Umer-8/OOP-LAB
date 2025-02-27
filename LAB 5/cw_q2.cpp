#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Car
{
    private:
    string name;
    int id;
    public:
    Car(string name,int id):name(name),id(id)
    {
        cout<<"Constructor called."<<endl;
    }

    string getname() const
    {
        return name;
    }
    int getId()const
    {
        return id;
    }
   ~Car()
    {
        cout<<"Destructor called."<<endl;

    }
};
class Garage
{
    private:
    vector<Car*>cars;
    public:
    void parkcar(Car *car)
    {
        cars.push_back(car);
    }
    void listcars() const
    {
        if(cars.empty())
        {
            cout<<"No cars in the park."<<endl;
        }
        else
        {
            for(const auto &car:cars)
            {
                cout<<"Car :"<<car->getname() <<" Id:"<<car->getId()<<endl;
            }
        }
    }
};
int main()
{
Car c1("Honda",1);
Car c2("Toyota",2);
Car c3("Mercedez",3);

Garage g;
g.parkcar(&c1);
g.parkcar(&c2);
g.parkcar(&c3);

g.listcars();
    return 0;
}