#include<iostream>
using namespace std;

int main()
{
    string name;
    int id,units;
    int charge,surcharge_amount=0,net_amount;

    cout<<"Enter name:"<<endl;
    cin>>name;
    cout<<"Enter customer id:"<<endl;
    cin>>id;
    cout<<"Enter units consumed:"<<endl;
    cin>>units;

    if(units>0 && units<=199)
    {
        charge=16.20*units;
    }
    else  if(units>=200 && units<300)
    {
        charge=20.10*units;
    }
    else if(units>=300 && units<500)
    {
        charge=27.10*units;
    }
    else  if(units>=500)
    {
        charge=35.90*units;
    }
    else
    {
      cout<<"Invalid units entered "<<endl;
      return 0;
    }
  if(charge>18000)
  {
    surcharge_amount=0.15*charge;
  }
  net_amount=surcharge_amount+charge;
  cout<<"Customer ID:"<<id<<endl;
  cout<<"Customer name:"<<name<<endl;
  cout<<"Units consumed:"<<units<<endl;
  cout<<"Amount charges:"<<charge<<endl;
  cout<<"Surcharge amount:"<<surcharge_amount<<endl;
  cout<<"Net amount:"<<net_amount<<endl;

  return 0;
}