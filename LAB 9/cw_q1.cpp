#include<iostream>
using namespace std;

class Wallet
{
    private:
    double balance;
    int dailyTransactionLimit=0;
    int maxDailyTransactionLimit=5;
    public:
    void deposit(int amount)
    {
        if(dailyTransactionLimit<=maxDailyTransactionLimit)
        {
        balance+=amount;
        }
    }
    void withdrawl(int amount)
    {
        if(amount<balance && dailyTransactionLimit<=maxDailyTransactionLimit)
        {
            balance-=amount;
        }
        else
        {
            cout<<"Insufficient balance to withdraw  amount."<<endl;
        }
        if(isToday)
        {
            dailyTransactionLimit++;
        }
    }
    void display()
    {
        cout<<"Balance: "<<balance<<endl;
    }
    bool isToday()
    {
        return true;
    }
    void setBalance(int Balance)
    {
        balance=Balance;
    }
};
class User
{
    private:
    int userID;
    string name;
    Wallet wallet;

    public:
    User(string name,int id,int balance):name(name),userID(id)
    {
        wallet.setBalance(balance);
    }
    void deposit(int amount)
    {
        wallet.deposit(amount);
    }
    void withdrawl(int amount)
    {
        wallet.withdrawl(amount);
    }
    void display()
    {
        wallet.display();
    }
   
   
};
int main()
{
    User u1("umer",1,40000);
    User u2("saim",2,30000);

    u1.deposit(20000);
    u1.display();
    u1.withdrawl(61000);
    u1.display();

    u2.deposit(20000);
    u2.display();
    u2.withdrawl(40000);
    u2.display();
    return 0;
}