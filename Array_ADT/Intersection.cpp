#include<iostream>
using namespace std;
struct Array{
    int A[10];
    int size;
    int length;
};

Array*Intersection(Array*arr1,Array*arr2){
    Array *arr3= new Array;

    int i=0,j=0,k=0;
    while (i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            i++;
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else {
            arr3->A[k++]=arr1->A[i++];
            j++;}
    }

    arr3->length = k;
    arr3->size = 10;
    
    return arr3;
    
}         

void Display(Array arr){
    cout<<"Elements are\n";
    for(int i=0;i<arr.length;i++)
        cout<<arr.A[i]<<" ";
}

int main(){
    Array arr1 = {{2,6,10,15,25},10,5};
    Array arr2 = {{3,6,7,15,20},10,5};
    Array *arr3 = Intersection(&arr1,&arr2);
    Display(*arr3);
    return 0;
}