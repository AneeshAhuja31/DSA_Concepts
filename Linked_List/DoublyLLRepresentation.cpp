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
    Display(head);
    return 0;
}