#include<iostream>
using namespace std;

int findMax(int A[],int n){
    int max=INT32_MIN;
    for(int i=0;i<n;i++){
        if(A[i]>max)
            max=A[i];
    }
    return max;
}
void CountSort(int A[],int n){
    int max = findMax(A,n);
    int*C = new int[max+1];

    for(int i=0;i<max+1;i++)
        C[i]=0;
    
    for(int i=0;i<n;i++)
        C[A[i]]++;
    
    int i=0,j=0;

    while(i<=max){ //while loop with dual purpose which are to make C[i] == 0 and to traverse through C
        if(C[i]>0){
            A[j++]=i;
            C[i]--;
        }
        else i++; //i only increases when C[i]==0
    }
}
int main(){
    int A[]={1,3,7,12,16,9,24,5,1,3},n=10;
    CountSort(A,n);
    for(int i=0;i<10;i++)
        cout<<A[i]<<" ";
    return 0;
}