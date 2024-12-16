#include<iostream>
using namespace std;

void InsertSort(int A[],int n){
    for(int i=0;i<n;i++){
        int key=A[i]; // The current element to be placed in the sorted part
        int j = i-1; //The sorted part starts here at an index before key element (i-1)
        
        // Move elements of A[0..i-1], that are greater than key, to one position ahead of their current position
        while(j>=0 && A[j]>key){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key; //Inserted key at correct position
    }
}

int main(){
    int A[]={3,7,9,10,6,5,12,4,11,2},n=10;
    InsertSort(A,n);
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    return 0;
}