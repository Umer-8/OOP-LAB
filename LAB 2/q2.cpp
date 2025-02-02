#include <iostream>
using namespace std;
void* add (void* array) {
 int *arr=(int*)array;

    int result=0;
    for(int i=0;i<5;i++){
    result+=arr[i];
    }
    void *ptr=(void*)&result;
    return ptr;
}
int main ()
 {
    int array[5]={10,20,30,40,50};
       void *ptr=(void*)array;
    int result=*(int*)add(ptr);
    cout<<result<<endl;
    return 0;
}