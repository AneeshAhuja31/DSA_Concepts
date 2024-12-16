#include<iostream>
using namespace std;
struct Array{
    int A[10];
    int size;
    int length;
};
int Get(Array arr,int index){
    if(index>=0 && index<arr.length)
        return arr.A[index];
    return -1; 
}
void Set(Array *arr,int index,int x){
    if(index>=0 && index<arr->length)
        arr->A[index]=x;
}
int Max(Array arr){
    int max = arr.A[0];
    for(int i=0;i<arr.length;i++)
        if (arr.A[i]>max)
            max = arr.A[i];
    return max;
}
int Min(Array arr){
    int min = arr.A[0];
    for(int i=0;i<arr.length;i++)
        if (arr.A[i]<min)
            min = arr.A[i];
    return min;
}
int Sum(Array arr){
    int s=0;
    for (int i=0;i<arr.length;i++)
        s+=arr.A[i];
    return s;
}
float Avg(Array arr){
    return (float)Sum(arr)/arr.length;
}
void Display(Array arr){
    cout<<"Elements are\n";
    for(int i=0;i<arr.length;i++)
        cout<<arr.A[i]<<" ";
}

int main(){
    Array arr = {{2,3,4,5,6},10,5};
    cout<<Get(arr,2)<<endl;
    Set(&arr,3,100);
    cout<<"MAX: "<<Max(arr)<<" MIN: "<<Min(arr)<<" AVG: "<<Avg(arr)<<endl;
    cout<<"Sum is: "<<Sum(arr)<<endl;
    Display(arr);
    return 0;
}