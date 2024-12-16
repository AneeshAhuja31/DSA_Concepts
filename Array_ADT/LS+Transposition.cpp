#include<iostream>
using namespace std;
struct Array{
    int A[10];
    int size;
    int length;
};
void swap(int*x,int*y){
    int temp;
    temp = *x;
    *x=*y;
    *y=temp;
}

int LinearSearchWTransposition(Array *arr,int key){
    for(int i=0;i<arr->length;i++)
        if(key==arr->A[i]){
            swap(&arr->A[i],&arr->A[i-1]);    //this will shift the position of searched element to the left by one space such that if it is searched again, it will require less time by the compiler to search for the element
            return i-1;}

    return -1;
}
void Display(Array arr){
    cout<<"Elements are\n";
    for(int i=0;i<arr.length;i++)
        cout<<arr.A[i]<<" ";
}

int main(){
    Array arr = {{2,3,4,5,6},10,5};
    cout<<LinearSearchWTransposition(&arr,6)<<endl;
    Display(arr);
    return 0;
}
