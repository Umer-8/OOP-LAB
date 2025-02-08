#include<iostream>
using namespace std;

class Date
{
    public:
    int day;
    int month;
    int year;
 
 void displaydate()
 {
    cout<<"Date is:"<<day<<"/"<<month<<"/"<<year<<endl;
 }

};
int main()
{
    Date d;
    cout<<"Enter date:"<<endl;
    cin>>d.day;
    cout<<"Enter month:"<<endl;
    cin>>d.month;
    cout<<"Enter year:"<<endl;
    cin>>d.year;

    d.displaydate();
    return 0;

}