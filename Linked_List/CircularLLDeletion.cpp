#include<iostream>
using namespace std;
struct Node{
    int data;
    Node*next;
}*head=NULL;  

void Create(Node*&p,int A[],int n){
    int i;
    Node*t,*last;
    p = new Node;
    p->data=A[0]; 
    p->next=p;
    last=p;
    for(int i=1;i<n;i++){
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
int Delete(Node*p,int pos){
    Node*q;
    int x;
    if(pos==0){
        while(p->next!=head) p=p->next;
        x=head->data;
        if(p==head){ //if p only has one node head
            delete head;
            head=NULL;
        }
        else{
            p->next=head->next;
            delete head;
            head=p->next;
        }
    }
    else{
        for(int i=0;i<pos-1;i++) p=p->next;
        q=p->next;
        p->next=q->next;
        x=q->data;
        delete q;
    }
    return x;
}

void Display(Node*p){
    do{
        cout<<p->data<<" ";
        p=p->next;
    }
    while(p!=head);
    cout<<endl;
}

int main(){
    int A[]={2,3,4,5,6};
    int n = sizeof(A)/sizeof(int);
    Create(head,A,n);
    int x =Delete(head,0);
    cout<<"Deleted Element: "<<x<<endl;
    Display(head);
}