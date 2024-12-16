#include<iostream>
#include"Chains.h"
using namespace std;

int hasher(int key){
    return key%10;
}
void Insert(Node*H[],int key){
    int index=hasher(key);
    SortedInsert(&H[index],key);
}
int main(){
    Node*HT[10],*temp;
    for(int i=0;i<10;i++)
        HT[i]=NULL;
    
    Insert(HT,12);
    Insert(HT,22);
    Insert(HT,42);
    
    temp=Search(HT[hasher(22)],22);
    cout<<temp->data;
    return 0;
}