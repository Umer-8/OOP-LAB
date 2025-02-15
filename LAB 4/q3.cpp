#include<iostream>
using namespace std;

class Invoice
{
    string part_number;
    string part_description;
    int quantity;
    double price;

    public:
    Invoice(string part_number,string part_description,int quantity,double price)
    {
       this->part_number=part_number;
       this->part_description=part_description;
       this->quantity=quantity;
       this->price=price;
    }
    double getinvoiceamount()
    {
        if(quantity<0 )
        {
            quantity=0;
        }
        if(price<0)
        {
            price=0.0;
        }
        return quantity*price;
    }
};
int main()
{
    string a,b;
    int c;
    double d;

    cout<<"Enter invoice number:"<<endl;
    cin>>a;
    cout<<"Enter invoice description:"<<endl;
    cin>>b;
    cout<<"Enter quantity:"<<endl;
    cin>>c;
    cout<<"Enter price:"<<endl;
    cin>>d;
    Invoice i(a,b,c,d);
 cout<<"Amount is:"<<i.getinvoiceamount();

return 0;
}