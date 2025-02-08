#include<iostream>
using namespace std;


class Glass
{
    public:
    int liquidlevel;

    void drink(int millimeters)
    {
      refill();
    }
   void refill()
    {
      liquidlevel=200;
    }
};

int main()

{
    int mm,remaining=200;
    
    Glass g;
    g.liquidlevel=200;

do
{
    cout<<"Enter millimeters to drink"<<endl;
    cin>>mm;

    remaining=g.liquidlevel-mm;
    if(remaining<100)
    {
    g.drink(remaining);
    }
}while(mm!=0);
return 0;
}