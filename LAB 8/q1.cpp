#include<iostream>
using namespace std;

class A
{
    private:
    float num;
    public:
    A(int num):num(num){}
    A operator --()
    {
        num*=4;
    }
    A operator --(int)
    {
        A temp=*this;
        num/=4;
        
    }
    void displaynum()
    {
        cout<<"Number is:"<<num<<endl;
    }
};
int main()
{
    A a(10);
    --a;
    a.displaynum();
    a--;
    a.displaynum();

}