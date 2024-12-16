#include<iostream>
using namespace std;

void Merge(int A[],int l,int mid,int h){
    int i=l,j=mid+1,k=0;
    int B[100];
    while(i<=mid && j<=h){
        if(A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }
    //Copying remianing elements after comparision
    for(;i<=mid;i++) B[k++]=A[i];  
    for(;j<=h;j++) B[k++]=A[j];
    k=0;   //Since elements are stored in B from idex 0
    for(int i=l;i<=h;i++)  //Copy elements from B to A
        A[i]=B[k++];
}

void IMergeSort(int A[],int n){
    int p,l,h,mid,i;
    for(p=2;p<=n;p=p*2){  //p represents the number of elements that are being merged in every pass
        for(i=0;i+p-1<n;i=i+p){  //this for loop merges the subarrays
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            Merge(A,l,mid,h);
        }
    }
    if(p/2<n) Merge(A,0,(p/2)-1,n-1); // to completely fill the array in case n is odd
}

void RMergeSort(int A[],int l,int h){
    if(l<h){
        int mid=(l+h)/2;
        RMergeSort(A,l,mid); //recursive call on the first half of the array
        RMergeSort(A,mid+1,h); //recursive call on the second half of the array
        Merge(A,l,mid,h); //to compare and merge the elements of subarrays
    }
}
int main(){
    int A[]={11,13,7,12,16,9,24,5,10,3},n=10;
    IMergeSort(A,n);
    for(int i=0;i<10;i++)
        cout<<A[i]<<" ";

    cout<<endl;

    int B[]={11,13,7,12,16,9,24,5,10,3},m=10;
    RMergeSort(B,0,m-1);
    for(int i=0;i<10;i++)
        cout<<B[i]<<" ";
    return 0;
}