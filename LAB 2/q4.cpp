#include<iostream>
using namespace std;

struct Employee
{
    string emp_name;
    int emp_id;
    int emp_salary;

}emp;
struct Organization
{
  string org_name;
  string org_number;
  Employee emp;
}org;

int main()
{
    org.org_name="NU-Fast";
    org.org_number="NUFAST123ABC";
    org.emp.emp_id=127;
    org.emp.emp_name="Linus Sebastian";
    org.emp.emp_salary=400000;

    cout<<"The size of structure organisation :"<<sizeof(org)<<endl;
    cout<<"Organisation Name :"<<org.org_name<<endl;
    cout<<"Organisation Number:"<<org.org_number<<endl;
    cout<<"Employee ID:"<<org.emp.emp_id<<endl;
    cout<<"Employee Name:"<<org.emp.emp_name<<endl;
    cout<<"Employee salary:"<<org.emp.emp_salary<<endl;
    return 0;
}
