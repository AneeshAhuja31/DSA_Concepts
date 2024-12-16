#include<iostream>
using namespace std;

void BubbleSort(int A[],int n){
    int flag=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){
                swap(A[j],A[j+1]);
                flag=1;
            }
        }
        if(flag==0) break;  //Improvement in bubble sort to make it faster
    }
}
int main(){
    int A[]={3,7,9,10,6,5,12,4,11,2},n=10;
    BubbleSort(A,n);
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    return 0;
}