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

Node* Merge(Node*p,Node*q){
    Node*first,*last;
    if(p->data<q->data){
        first=last=p; //first acts as the head node and is returned in the end
        p=p->next;
        first->next=NULL;
    }
    else{
        first=last=q;
        q=q->next;
        first->next=NULL;
    }
    while(p!=NULL && q!=NULL){
        if(p->data<q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p!=NULL) last->next = p;
    if(q!=NULL) last->next = q;

    return first;
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
    Node*f=Merge(head1,head2);
    Display(f);
    return 0;
}