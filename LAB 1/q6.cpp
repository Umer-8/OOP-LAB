#include <iostream>
#include <iomanip> 
using namespace std;

int main()
{
    string name;
    float score[5];
    float sum=0,avg=0;

    cout << fixed << setprecision(2); 

    cout<<"Enter name:"<<endl;
    cin>>name;
    for(int i=0;i<5;i++)
    {
        cout<<"Enter test score "<<(i+1)<<endl;
        cin>>score[i];
        sum+=score[i];
    }
    avg=sum/5;

    cout<<"Student name:"<<name<<endl;
    cout<<"Test scores:"<<endl;
     for(int i=0;i<5;i++)
    {
        cout<<score[i]<<endl;
    }
    cout<<"Average test score:"<<avg<<endl;
    return 0;

}