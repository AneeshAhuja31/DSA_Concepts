#include<iostream>
using namespace std;
struct Array{
    int A[10];
    int size;
    int length;
};
int Delete(Array*arr,int index){
    int x=0;
    if(index>=0 && index<=arr->length)
        x = arr->A[index];
        for(int i=index;i<arr->length-1;i++)
            arr->A[i] = arr->A[i+1];
        
        arr->length--;
        return x;
    
    return 0;
}


void Display(Array arr){
    cout<<"Elements are\n";
    for(int i=0;i<arr.length;i++)
        cout<<arr.A[i]<<" ";
}

int main(){
    Array arr = {{2,3,4,5,6},10,5};
    cout<<"Deleted Element: "<<Delete(&arr,4)<<endl;
    Display(arr);
    return 0;
}
