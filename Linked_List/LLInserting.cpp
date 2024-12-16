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
void Insert(int pos,int x){
    Node*p,*t; //t is the node to be inserted whereas p is temporary
    if(pos==0){
        t=new Node;
        t->data = x;
        t->next = head;
        head = t;
    }
    else if(pos>0){
        p = head;
        for(int i=0;i<pos-1 && p;i++) //&& p is to stop loop if p is NULL
            p=p->next;
        if(p){
            t = new Node;
            t->data=x;
            t->next = p->next;
            p->next = t;
        }
    }
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
    Insert(1,4);
    Display(head);
    return 0;
}