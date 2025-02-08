#include<iostream>
#include<string>
using namespace std;


class Employee
{
    public:
    string firstname;
    string lastname;
    double salary;

   void testsalary()
    {
        if(salary<0)
        {
            salary=0.0;
        }
    }
    double display_yearly_salary()
    {
        salary=salary*12;
        return salary;
    }
    double display_raised_salary()
    {
        salary=salary*1.1;
        return salary;
    }
};

int main()
{

  Employee e1,e2;

  cout<<"Enter firstname of first employee:"<<endl;
  cin>>e1.firstname;
  cout<<"Enter lastname of first employee:"<<endl;
  cin>>e1.lastname; 

   cout<<"Enter firstname of second employee:"<<endl;
   cin>>e2.firstname;
   cout<<"Enter lastname of second employee:"<<endl;
   cin>>e2.lastname;
  
  cout<<"Enter salary of first employee:"<<endl;
  cin>>e1.salary;
  e1.testsalary();

  cout<<"Enter salary of second employee:"<<endl;
  cin>>e2.salary;
  e2.testsalary();

  cout<<"Yearly salary of "<<e1.firstname<<" "<<e1.lastname <<":"<<e1.display_yearly_salary()<<endl;
  cout<<"Yearly salary of "<<e2.firstname<<" "<<e2.lastname <<":"<<e2.display_yearly_salary()<<endl;

  cout<<"Salary after raise of "<<e1.firstname<<" "<<e1.lastname <<":"<<e1.display_raised_salary()<<endl;
  cout<<"Salary after raise of "<<e2.firstname<<" "<<e2.lastname <<":"<<e2.display_raised_salary()<<endl;

  return 0;

}