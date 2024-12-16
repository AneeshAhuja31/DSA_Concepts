#include<iostream>
using namespace std;
int MissingElement(int arr[],int n){
    int diff = arr[0];
    for(int i=0;i<n;i++)
        if(arr[i]-i!=diff){
            return i+diff;
        }
}
int main(){
    int arr[]= {6,7,8,9,10,11,13,14,15,16,17};
    int n = (sizeof(arr)/sizeof(int));
    cout<<"Missing Element is: "<<MissingElement(arr,n);
    return 0;
}