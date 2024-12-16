#include<iostream>
using namespace std;
struct Array{
    int A[10];
    int size;
    int length;
};
void Reversal1(Array *arr){
    int B[arr->length];
    for(int i=arr->length-1,j=0;i>=0;i--,j++)
        B[j]=arr->A[i];
    for(int i=0;i<arr->length;i++)
        arr->A[i]=B[i];
}
void Reversal2(Array *arr) {
    for (int i = 0, j = arr->length - 1; i < j; i++, j--) {
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}
void Display(Array arr){
    cout<<"Elements are\n";
    for(int i=0;i<arr.length;i++)
        cout<<arr.A[i]<<" ";
}

int main(){
    Array arr = {{2,3,4,5,6},10,5};
    Reversal1(&arr);
    Display(arr);
    Reversal2(&arr);
    cout<<endl;
    Display(arr);
    return 0;
}