#include<iostream>
using namespace std;
struct Array{
    int A[10];
    int size;
    int length;
};

int LinearSearch(Array arr,int key){
    for(int i=0;i<arr.length;i++)
        if(key==arr.A[i])
            return i;
    return -1;
}
void Display(Array arr){
    cout<<"Elements are\n";
    for(int i=0;i<arr.length;i++)
        cout<<arr.A[i]<<" ";
}

int main(){
    Array arr = {{2,3,4,5,6},10,5};
    cout<<LinearSearch(arr,6)<<endl;
    Display(arr);
    return 0;
}
