#include<iostream>
using namespace std;
void Duplicates1(int A[],int n){
    int*H = new int[10];
    for(int i=0;i<10;i++){
        H[i] = 0;
    }
    for(int i=0;i<n;i++){
       H[A[i]]++; 
    }
    for(int i=0;i<10;i++){
        if(H[i]>1){
            cout<<i<<" ";}
    }
    delete[] H;
} 
void Duplicates2(int A[],int n){
    for(int i=0;i<n;i++){
        int count=1;
        for(int j=i+1;j<n;j++){
            if(A[i]==A[j]){
                count++;
                
            }
        if(count>1) cout<<A[i];
        for(int j=i;j<n;j++) A[j]=-1;
        }
    }
}
int main(){
    int arr[]={8,3,6,4,6,5,6,8,2,7};
    Duplicates2(arr,10);
    return 0;
}