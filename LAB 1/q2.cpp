#include<iostream>
using namespace std;

void function(int *array,int *sum)
{
    for(int i=0;i<10;i++)
    {
        *sum+=array[i];
    }
}
int main()
{
    int array[10];
    int sum=0;
    for(int i=0;i<10;i++)
    {
        cout<<"Enter number "<<i+1<<endl;
        cin>>array[i];
    }
    function(array,&sum);
    cout<<"The sum is "<<sum<<endl;
    return 0;
}