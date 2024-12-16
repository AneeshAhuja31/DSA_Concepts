#include<iostream>
using namespace std;
struct Node{
    int data;
    Node*next;
}*head=NULL;  

void Create(int A[],int n){
    Node*t,*last;
    head = new Node; 
    head->data = A[0]; 
    head->next=NULL;  
    last = head; 

    for(int i=1;i<n;i++){
        t = new Node; 
        t->data=A[i]; 
        t->next=NULL;
        last->next=t; 
        last = t; 
    }
}
void SortedInsert(int x){
    Node*p,*t; 
    p = head;
    
    t = new Node;
    t->data = x;
    t->next = nullptr;

    while(p->next && p->next->data<x){
        
        p = p->next;
    }
    
    t->next = p->next;
    p->next = t;
    
    
}

void Display(Node*p){
    while(p != NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
}
int main(){
    int A[] = {3, 5, 7, 10, 15};
    int n = sizeof(A)/sizeof(int);
    Create(A, n);
    SortedInsert(8);
    Display(head);
    return 0;
}