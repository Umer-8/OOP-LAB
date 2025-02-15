#include<iostream>
using namespace std;

class Account
{
    private:
    double account_balance;

    public:
    Account()
    {
        account_balance=10000;
    }
    void addamount(int amount)
    {
        
      account_balance+=amount;
    }
    void withdrawamount(int amount)
    {
        if(account_balance>amount)
        {
        account_balance-=amount;
        }
        else
        {
            cout<<"Insufficient account balance."<<endl;
        }
    }
    void checkbalance()
    {
        cout<<"Your current balance is :"<<account_balance<<endl;
    }

};
int main()
{
    Account a;
    int choice,amount;
    while(1)
    {
        cout<<"Enter 1 to add amount.Enter 2 to withdraw amount.Enter 3 to check balance.Enter 4 to exit "<<endl;
        cin>>choice;
    switch(choice)
    {
     case 1:
     cout<<"Enter amount to add:"<<endl;
     cin>>amount;
     a.addamount(amount);
     break;

     case 2:
     cout<<"Enter amount to withdraw:"<<endl;
     cin>>amount;
     a.withdrawamount(amount);
     break;

     case 3:
     a.checkbalance();
     break;

     case 4:
     return 0;

     default:
     cout<<"Invalid choice.Please try again."<<endl;
    }
}
}