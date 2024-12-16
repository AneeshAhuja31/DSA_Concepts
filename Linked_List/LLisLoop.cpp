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

int isLoop(Node*f){
    Node*p,*q;
    p=q=f;
    do{
        p=p->next;
        q=q->next;
        q=(q!=NULL?q->next:q);
    }while(p && q && p!=q);
    if(p==q)
        return 1;
    else
        return 0;
}

void Display(Node*p){
    while(p != NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
}
int main(){
    Node*t1,*t2;
    int A[] = {10,20,30,40,50};
    int n = sizeof(A)/sizeof(int);
    Create(A, n);
    t1=head->next->next;
    t2=head->next->next->next->next;
    t2->next=t1;
    cout<<isLoop(head);
    return 0;
}