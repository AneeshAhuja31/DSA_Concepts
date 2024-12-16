#include<iostream>
using namespace std;
struct Array{
    int A[10];
    int size;
    int length;
};

void Display(Array arr){
    cout<<"Elements are\n";
    for(int i=0;i<arr.length;i++)
        cout<<arr.A[i]<<" ";
}
void InsertSort(Array*arr,int x){
    int i=arr->length-1;
    while(i>=0 && arr->A[i]>x){
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

int main(){
    Array arr = {{2,3,5,10,15},10,5};
    InsertSort(&arr,11);
    Display(arr);
    return 0;
}