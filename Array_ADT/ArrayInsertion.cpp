#include<iostream>
using namespace std;
struct Array{
    int A[10];
    int size;
    int length;
};
void Insert(Array*arr,int index,int x){
    if(index>=0 && index<=arr->length)
        for(int i=arr->length;i>index;i--)
            arr->A[i] = arr->A[i-1];
        
        arr->A[index] = x;
        arr->length++;
         
}
void Display(Array arr){
    cout<<"Elements are\n";
    for(int i=0;i<arr.length;i++)
        cout<<arr.A[i]<<" ";
}

int main(){
    Array arr = {{2,3,4,5,6},10,5};
    Insert(&arr,4,69);
    Display(arr);
    return 0;
}