#include<iostream>
using namespace std;
struct Array{
    int A[10];
    int size;
    int length;
};

Array*Merge(Array*arr1,Array*arr2){
    Array *arr3= new Array;
    arr3->length = arr1->length+arr2->length;
    arr3->size = arr1->size+arr2->size;

    int i=0,j=0,k=0;
    while (i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else 
            arr3->A[k++]=arr2->A[j++];
    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];
    
    return arr3;
    
}         

void Display(Array arr){
    cout<<"Elements are\n";
    for(int i=0;i<arr.length;i++)
        cout<<arr.A[i]<<" ";
}

int main(){
    Array arr1 = {{3,8,16,20,25},10,5};
    Array arr2 = {{4,10,12,22,23},10,5};
    Array*arr3 = Merge(&arr1,&arr2);
    Display(*arr3); //since it is call by value
    return 0;
}