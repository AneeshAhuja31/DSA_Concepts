#include<iostream>
using namespace std;
struct Node{
    Node*prev;
    int data;
    Node*next;
}*head=NULL;

void Create(Node*&p,int A[],int n){
    Node*t,*last;
    int i;
    p = new Node;
    p->data = A[0];
    p->prev=p->next=NULL;
    last=p;

    for(i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }

}
void Insert(Node*&p,int pos,int x){
    Node*t=new Node;
    if(pos==0){
        t->data=x;
        t->prev=NULL;
        t->next=p;
        p->prev=t;
        p=t;
    }
    else{
        Node*curr = p;
        for(int i=0;i<pos-1;i++) curr=curr->next;
        t->data=x;
        t->next=curr->next;
        t->prev=curr;
        if(curr->next) curr->next->prev=t;
        curr->next=t;
    }
}
void Display(Node*p){
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main(){
    int A[]={10,20,30,40,50};
    int n=sizeof(A)/sizeof(int);
    Create(head,A,n);
    Insert(head,0,19);
    Display(head);
    return 0;
}