#include<iostream>
using namespace std;

class Vehicles
{
    protected:
    int price;
};
class Car:public Vehicles
{
    protected:
    int seating_capacity;
    int num_doors;
    string fuel_type;
};
class Motorcycle:public Vehicles
{
    protected:
    int num_cylinders;
    int num_gears;
    int num_wheels;

};
class Audi:public Car
{
    string model_type;
    public:
    Audi(int price,int seating_capacity,int num_doors,string fuel_type,string model_type)
    {
        cout<<"AUDI DETAILS:"<<endl;
        this->price=price;
        this->seating_capacity=seating_capacity;
        this->num_doors=num_doors;
        this->fuel_type=fuel_type;
        this->model_type=model_type;
    }
    void displayCar()
    {
        cout<<"Price:"<<price<<endl;
        cout<<"Seating capacity:"<<seating_capacity<<endl;
        cout<<"Number of doors:"<<num_doors<<endl;
        cout<<"Fuel type:"<<fuel_type<<endl;
        cout<<"Model type:"<<model_type<<endl;
    }
};
class Yamaha:public Motorcycle
{
    string make_type;
    public:
    Yamaha(int price,int num_cylinders,int num_gears,int num_wheels,string make_type)
    {
        this->price=price;
        this->num_cylinders=num_cylinders;
        this->num_gears=num_gears;
        this->num_wheels=num_wheels;
        this->make_type=make_type;
    }
    void displayMotorcycle()
    {
        cout<<"YAMAHA DETAILS:"<<endl;
        cout<<"Price:"<<price<<endl;
        cout<<"Number of cylinders:"<<num_cylinders<<endl;
        cout<<"Number of gears:"<<num_gears<<endl;
        cout<<"Number of wheels:"<<num_wheels<<endl;
        cout<<"Make type:"<<make_type<<endl;
    }
};
int main()
{
    int pricecar,pricebike,seating_capacity,num_doors,num_cylinders,num_gears,num_wheels;
    string fuel_type,model_type,make_type;

    cout<<"Enter price of AUDI:"<<endl;
    cin>>pricecar;

    cout<<"Enter seating capacity of the car:"<<endl;
    cin>>seating_capacity;

    cout<<"Enter number of doors of the car:"<<endl;
    cin>>num_doors;

    cout<<"Enter fuel type of the car:"<<endl;
    cin>>fuel_type;

    cout<<"Enter model type of the car:"<<endl;
    cin>>model_type;

    cout<<"Enter price of YAMAHA:"<<endl;
    cin>>pricebike;

    cout<<"Enter number of cylinders of the bike:"<<endl;
    cin>>num_cylinders;

    cout<<"Enter number of gears of the bike:"<<endl;
    cin>>num_gears;

    
    cout<<"Enter number of wheels of the bike:"<<endl;
    cin>>num_wheels;

    cout<<"Enter make type of the bike:"<<endl;
    cin>>make_type;
    
    Audi a(pricecar,seating_capacity,num_doors,fuel_type,model_type);
    Yamaha y(pricebike,num_cylinders,num_gears,num_wheels,make_type);

    a.displayCar();
    y.displayMotorcycle();
    return 0;
}