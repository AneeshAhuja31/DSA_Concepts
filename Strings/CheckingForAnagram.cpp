#include<iostream>
using namespace std;
int main(){
    char A[] = "verbose";
    char B[] = "observe";
    int H1[26] = {0};
    int H2[26] = {0};
    for(int i=0;A[i]!='\0';i++){
        H1[A[i]-'a'] += 1;
    }
    for(int i=0;B[i]!='\0';i++){
        H2[B[i]-'a'] += 1;
    }
    for(int i=0;i<26;i++){
        if(H1[i]!=H2[i]){
            cout<<"false";
            return 0;
        }
    }
    cout<<"true";
    
    return 0;
}