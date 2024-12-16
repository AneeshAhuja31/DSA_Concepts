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

int LinearSearchWMoveToFront(Array *arr,int key){
    for(int i=0;i<arr->length;i++)
        if(key==arr->A[i]){
            swap(&arr->A[i],&arr->A[0]);    //this will swap the position of searched element to the first element of the array such that if it is searched again, it will require least amount of time by the compiler to search for the element again
            return 0;}

    return -1;
}
void Display(Array arr){
    cout<<"Elements are\n";
    for(int i=0;i<arr.length;i++)
        cout<<arr.A[i]<<" ";
}

int main(){
    Array arr = {{2,3,4,5,6},10,5};
    cout<<LinearSearchWMoveToFront(&arr,6)<<endl; //0
    Display(arr);
    return 0;
}
