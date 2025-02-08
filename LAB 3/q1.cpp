#include<iostream>
using namespace std;

class User
{
    public:
    int age;
    string name;
};
int main()
{
    User u;
    u.age=24;
    u.name="Teo";
    cout<<"Age:"<<u.age<<endl;
    cout<<"Name:"<<u.name<<endl;
    return 0;
}