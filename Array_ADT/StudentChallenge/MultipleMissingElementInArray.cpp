#include<iostream>
using namespace std;
void MissingElements(int arr[],int n){
    int diff = arr[0];
    for(int i=0;i<n;i++){
        while(arr[i]-i!=diff){
            cout<<i+diff<<" ";
            diff++;
        }            
    }
}



int main(){
    int arr[] = {6,7,8,9,11,12,15,16,18,19};
    int n = (sizeof(arr)/sizeof(int));
    MissingElements(arr,n);
    return 0;
}