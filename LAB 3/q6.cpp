#include<iostream>
using namespace std;

class Matrix
{
    public:
    int rows;
    int columns;
    int rows2;
    int columns2;

    int** elements;
    int** elements2;

    int getrows()
    {
    return rows;
    }
    int getcolumns()
    {
    return columns;
    }
    int getrows2()
    {
    return rows2;
    }
    int getcolumns2()
    {
    return columns2;
    }

   void setelements(int a,int b)
   {
      elements = new int*[a];
      for(int i=0;i<a;i++)
      {
        elements[i] = new int[b];
        for(int j=0;j<b;j++)
        {
          cout<<"Enter element "<<j+1<<" of row "<<i+1<<endl;
          cin>>elements[i][j];
        }
      }
   }
   
   void setelements2(int c,int d)
   {
      elements2 = new int*[c];
      for(int i=0;i<c;i++)
      {
        elements2[i] = new int[d];
        for(int j=0;j<d;j++)
        {
          cout<<"Enter element "<<j+1<<" of row "<<i+1<<endl;
          cin>>elements2[i][j];
        }
      }   
   }
   void addmatrix(int a,int b,int c,int d, int** add)
   {
      if (a!=c || b!=d)
      {
        cout<<"Matrix cannot be added"<<endl;
      }
      else
      {
        for(int i=0;i<a;i++)
        {
          for(int j=0;j<b;j++)
          {
            add[i][j]=elements[i][j]+elements2[i][j];
          }
        }    
      }
   }
   void multiplymatrix(int a, int b, int c, int d, int** mul)
   {
      if (b != c)
      {
          cout << "Matrix cannot be multiplied" << endl;
      }
      else
      {
          for(int i=0; i<a; i++)
          {
              for(int j=0; j<d; j++)
              {
                  mul[i][j] = 0;
                  for(int k=0; k<b; k++)
                  {
                      mul[i][j] += elements[i][k] * elements2[k][j];
                  }
              }
          }
      }
   }
Matrix()
{
  rows=2;
  columns=2;
  rows2=2;
  columns2=2;
  elements = nullptr;
  elements2 = nullptr;
}
};


int main()
{
  Matrix mat;

  int a=mat.getrows();
  int b=mat.getcolumns();

  int c=mat.getrows2();
  int d=mat.getcolumns2();

  mat.setelements(a,b);
  mat.setelements2(c,d);

  int** result = new int*[a];
  for(int i=0; i<a; i++)
      result[i] = new int[b];
  
  mat.addmatrix(a,b,c,d,result);

  cout << "Addition Result:" << endl;
  for(int i=0;i<a;i++)
  {
      for(int j=0;j<b;j++)
      {
        cout<<result[i][j]<<" ";
      }
      cout<<endl;
  }
  
  int** mul = new int*[a];
  for(int i=0; i<a; i++)
      mul[i] = new int[d];
  
  mat.multiplymatrix(a,b,c,d,mul);

  cout << "Multiplication Result:" << endl;
  for(int i=0;i<a;i++)
  {
      for(int j=0;j<d;j++)
      {
        cout<<mul[i][j]<<" ";
      }
      cout<<endl;
  }
  
  return 0;
}