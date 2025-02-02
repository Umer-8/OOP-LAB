#include<iostream>
#include<cstring>
using namespace std;

struct X
{
    string name;
    int id;
}Z[5];
int main()
{
    for(int i=0;i<5;i++)
    {
      cout<<"Enter name "<<(i+1)<<":"<<endl;
      cin>>Z[i].name;
      cout<<"Enter id "<<(i+1)<<":"<<endl;
      cin>>Z[i].id;
    }
    for(int j=0;j<5;j++)
    {
        for(int k=0;k<5-j-1;k++)
        {
            if(Z[k].id>Z[k+1].id)
            {
               int temp=Z[k].id;
               Z[k].id=Z[k+1].id;
               Z[k+1].id=temp;
               string temp2=Z[k].name;
               Z[k].name=Z[k+1].name;
               Z[k+1].name=temp2;
            }
        }
    }
    cout<<"Sort by ID"<<endl;
    for(int j=0;j<5;j++)
    {
        cout<<Z[j].id<<"."<<Z[j].name<<endl;
    }
      for(int j=0;j<5;j++)
    {
     for(int k=0;k<5-j-1;k++)
        {
           if(Z[k].name>Z[k+1].name)
            {
              string temp2=Z[k].name;
               Z[k].name=Z[k+1].name;
               Z[k+1].name=temp2;
                int temp=Z[k].id;
               Z[k].id=Z[k+1].id;
               Z[k+1].id=temp;
            }
        }
    }

    cout<<"Sort by Name"<<endl;
    for(int j=0;j<5;j++)
    {
       cout<<Z[j].id <<"."<<Z[j].name<<endl;
    }
    return 0;

}