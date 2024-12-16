#include<iostream>
using namespace std;
void Duplicate(int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]==arr[i+1])
            cout<<arr[i]<<" ";
        while(arr[i]==arr[i+1]){
            i++;
        }
    }
}
int main(){
    int arr[]={3,6,8,8,10,10,10,10,12,15,15,15,20};
    int n = sizeof(arr)/sizeof(int);
    Duplicate(arr,n);
    return 0;
}