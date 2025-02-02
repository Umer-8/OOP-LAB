#include<iostream>
using namespace std;

int main()
{
    int sum=0;
    int array[5];
    int *arrptr=array;
    for(int i=0;i<5;i++)
    {
     cout<<"Enter element "<<(i+1)<<":"<<endl;
     cin>>arrptr[i];
     sum+=arrptr[i];
    }
    cout<<"Sum is "<<sum<<endl;
    return 0;
}