#include<iostream>
using namespace std;

int Partition(int A[],int l,int h){  
    int pivot=A[l];
    int i=l,j=h;
    do{
        do{i++;}while(A[i]<=pivot); //put i where A[i]>pivot
        do{j--;}while (A[j]>pivot); //put j where A[j]<=pivot

        if(i<j) swap(A[i],A[j]); //then swap
    } while(i<j);
    swap(A[l],A[j]); //swap pivot and element at j when i>j
    return j; //return index of sorted element
}

void QuickSort(int A[],int l,int h){
    int j; //j is the partitioning element
    if(l<h){  //Recursion will end when l=h which means when there is only one element to sort
        j=Partition(A,l,h);
        QuickSort(A,l,j);  //Element at j will act as INT_MAX
        QuickSort(A,j+1,h); 
    }
}
int main(){
    int A[]={11,13,7,12,16,9,24,5,10,3,INT32_MAX},n=11,i;
    QuickSort(A,0,n-1);
    for(int i=0;i<10;i++)
        cout<<A[i]<<" ";
    return 0;
}