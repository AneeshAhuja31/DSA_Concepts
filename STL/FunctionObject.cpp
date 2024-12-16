#include<iostream>
#include<functional>
#include<algorithm>
using namespace std;
int main(){
    //Function Objects: Function wrapped in a class
    int arr[] = {1,73,4,100,54, 7};
    sort(arr,arr+5);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    sort(arr,arr+5,greater<int>()); //greater element first
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}