#include<iostream>
using namespace std;

class student
{
    
    int id;
    string name;

    public:
   
    void setname(string name)
    {
        this->name=name;
    }
    void setID(int id)
    {
        this->id=id;
    }
    void getStudentDetails()
    {
        cout<<"NAME:"<<name<<endl;
        cout<<"ID:"<<id<<endl;
    }
};
class marks:public student
{
    protected:
    int marks_pf,marks_oop,marks_ds,marks_db;

    public:
    void getMarks()
    {
        cout<<"PF MARKS:"<<marks_pf<<endl;
        cout<<"OOP MARKS:"<<marks_oop<<endl;
        cout<<"DS MARKS:"<<marks_ds<<endl;
        cout<<"DB MARKS:"<<marks_db<<endl;
    }
};
class result:public marks
{
    protected:
    int total_marks;
    double avg_marks;

    public:
    result(string Name,int Id,int marks_pf,int marks_oop,int marks_ds,int marks_db)
    {
        setname(Name);
        setID(Id);
        this->marks_pf=marks_pf;
        this->marks_oop=marks_oop;
        this->marks_ds=marks_ds;
        this->marks_db=marks_db;
    }
    void calculateMarks()
    {
        total_marks=marks_pf+marks_oop+marks_ds+marks_db;
        avg_marks=(marks_pf+marks_oop+marks_ds+marks_db)/4;

        cout<<"TOTAL MARKS:"<<total_marks<<endl;
        cout<<"AVERAGE MARKS:"<<avg_marks<<endl;
    }

    void display()
    {
        getStudentDetails();
        getMarks();
        calculateMarks();
    }
};
int main()
{
    

    string name;
    int id,marks_pf,marks_oop,marks_ds,marks_db,total_marks;

    cout<<"Enter name:"<<endl;
    cin>>name;

    cout<<"Enter ID:"<<endl;
    cin>>id;

    cout<<"Enter PF marks:"<<endl;
    cin>>marks_pf;

    cout<<"Enter OOP marks:"<<endl;
    cin>>marks_oop;

    cout<<"Enter DS marks:"<<endl;
    cin>>marks_ds;

    cout<<"Enter DB marks:"<<endl;
    cin>>marks_db;

    result r(name,id,marks_pf,marks_oop,marks_ds,marks_db);
    r.display();

    return 0;
}

