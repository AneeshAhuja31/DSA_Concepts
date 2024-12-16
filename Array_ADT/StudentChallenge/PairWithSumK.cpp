#include<iostream>
using namespace std;
void Pair(int A[],int n){
    for(int i=0;i<n;i++){
        if(i<=10){
            for(int j=i+1;j<n;j++){
                if(A[i]+A[j]==10) cout<<"("<<A[i]<<" "<<A[j]<<")";
            }
        }
    }
}
int main(){
    int arr[10]={6,3,8,10,16,7,5,2,9,14};
    Pair(arr,10);
    return 0;
}