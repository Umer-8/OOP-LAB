#include<iostream>
using namespace std;

void function(float *array,float high,float *sechigh)
{
    int count;
     for(int i=0;i<20;i++)
    {
      if(array[i]>high)
      {
        high=array[i];
        count=i;
      }
    }
    array[count]=-1;
     for(int i=0;i<20;i++)
    {
      if(array[i]>*sechigh)
      {
        *sechigh=array[i];
      }
    }
}
int main()
{
float array[20];
float high=0,high2=0;
    for(int i=0;i<20;i++)
    {
        cout<<"Enter number"<<i+1<<endl;
        cin>>array[i];
    }
        function(array,high,&high2);
        cout<<"Second highest number is"<<high2<<" "<<endl;
        return 0;
}