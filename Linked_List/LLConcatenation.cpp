#include<iostream>
using namespace std;
struct Node{
    int data;
    Node*next;
}*head1=NULL,*head2=NULL;  

void Create(Node*&p,int A[],int n){ 
    Node*t,*last;
    p = new Node; 
    p->data = A[0]; 
    p->next=NULL;  
    last = p; 

    for(int i=1;i<n;i++){
        t = new Node; 
        t->data=A[i]; 
        t->next=NULL;
        last->next=t; 
        last = t; 
    }
}

void Concat(Node*p,Node*q){
    while (p->next!=NULL)
        p=p->next;
    p->next=q; 
}

void Display(Node*p){
    while(p != NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
}
int main(){
    int A[] = {3, 5, 7, 10, 15};
    int B[] = {2, 4, 6, 8, 9};
    int n = sizeof(A)/sizeof(int);
    int m = sizeof(B)/sizeof(int);
    Create(head1,A, n);
    Create(head2,B, m);
    Concat(head1,head2);
    Display(head1);
    return 0;
}