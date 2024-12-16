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
void Insert(int pos,int x){
    Node*t,*p;
    int i;
    if(pos==0){
        t=new Node;
        t->data=x;
        if(head==NULL){
            head=t;
            head->next=head;
        }
        else{
            p=head;
            while(p->next!=head) p=p->next;
            p->next=t;
            t->next=head;
            head=t;
        }
    }
    else{
        p=head;
        for(i=0;i<pos-1;i++)
            p=p->next;
        t=new Node;
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
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
    Insert(0,7);
    Display(head);
}