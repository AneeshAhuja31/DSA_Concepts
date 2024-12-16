#include<iostream>
using namespace std;
struct Array{
    int A[10];
    int size;
    int length;
};
int BinarySearch(Array arr,int key){
    int l=0,mid,h=arr.length-1;
    while (l<=h)
    {
        mid = (l+h)/2;
        if(key==arr.A[mid])
            return mid;
        else if (key<arr.A[mid])
            h = mid - 1;
        else 
            l = mid + 1;
    }
    return -1; 
}

void Display(Array arr){
    cout<<"Elements are\n";
    for(int i=0;i<arr.length;i++)
        cout<<arr.A[i]<<" ";
}

int main(){
    Array arr = {{2,3,4,5,6},10,5};
    cout<<BinarySearch(arr,5)<<endl;  //3
    Display(arr);
    return 0;
}
