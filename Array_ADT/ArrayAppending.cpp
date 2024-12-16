#include<iostream>
using namespace std;
struct Array{
    int A[10];
    int size;
    int length;
};
void Append(Array*arr,int x){
    if(arr->length<arr->size)
        arr->A[arr->length++] = x; //x is appended at the last index
}

void Display(Array arr){
    cout<<"Elements are\n";
    for(int i=0;i<arr.length;i++)
        cout<<arr.A[i]<<" ";
}

int main(){
    Array arr = {{2,3,4,5,6},10,5};
    Append(&arr,8);
    Display(arr);
    return 0;
}
