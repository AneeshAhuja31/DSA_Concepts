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
void Rearrange(Array*arr){
    int i=0,j=arr->length-1;
    while(i<j){
        while(arr->A[i]<0)i++;
        while(arr->A[j]>=0)j--;
        if(i<j){
            int temp=arr->A[i];
            arr->A[i]=arr->A[j];
            arr->A[j]=temp;
        }
    }

}

int main(){
    Array arr = {{2,-3,5,-8,10,-15},10,5};
    Rearrange(&arr);
    Display(arr);
    return 0;
}