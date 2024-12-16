#include<iostream>
using namespace std;
void funB(int n); //must be declared before
void funA(int n){
    if(n>0){
        cout<<n<<" ";
        funB(n-1); //this is possible as funB is declared before
    }
}
void funB(int n){
    if(n>1){
        cout<<n<<" ";
        funA(n/2);
    }
}
int main(){
    funA(20);
    return 0;
}