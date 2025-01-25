#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main()
{
    string movie_name;
    int childtickets,adulttickets,total_tickets;
    float gross_amount,percent_donatedamount,amount_donated,net_sale,childtickets_price,adulttickets_price;

    cout<<"Enter movie name:"<<endl;
    cin>>movie_name;
    cout<<"Enter child tickets sold:"<<endl;
    cin>>childtickets;
    cout<<"Enter child tickets price:"<<endl;
    cin>>childtickets_price;
    cout<<"Enter adult tickets sold:"<<endl;
    cin>>adulttickets;
    cout<<"Enter adult tickets price:"<<endl;
    cin>>adulttickets_price;
    cout<<"Enter percentage of amount donated:"<<endl;
    cin>>percent_donatedamount;


    cout << fixed << setprecision(2); 

    total_tickets=childtickets+adulttickets;

    gross_amount=(childtickets*childtickets_price)+(adulttickets*adulttickets_price);

    amount_donated=gross_amount*(percent_donatedamount/100);

    net_sale=gross_amount-amount_donated;

    cout<<"Movie Name:.........."<<movie_name<<endl;
    cout<<"Number of tickets sold:.........."<<total_tickets<<endl;
    cout<<"Gross Amount:..........$"<<gross_amount<<endl;
    cout<<"Percentage of gross amount donated:.........."<<percent_donatedamount<<"%"<<endl;
    cout<<"Amount Donated:.........."<<amount_donated<<endl;
    cout<<"Net Sale:.........."<<net_sale<<endl;

    return 0;
}


