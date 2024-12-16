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
Node* LSearch(Node*p,int key){
    while(p!=NULL){
        if(key==p->data)
            return p;
        p=p->next;
    }
    return NULL;
}
//MOVE TO HEAD
Node*LSearchWMoveToHead(Node*p,int key){
    Node*q=NULL;
    while(p!=NULL){
        if(key==p->data){
            q->next = p->next;
            p->next = head;
            head = p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
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
    Node*temp1=LSearch(head,10);
    if(temp1)
        cout<<"Key is found "<<temp1->data<<endl;
    else 
        cout<<"Key not found"<<endl;
    Node*temp2 = LSearchWMoveToHead(head,7);

    if(temp2)
        cout<<"Key is found "<<temp2->data<<endl;
    else 
        cout<<"Key not found"<<endl;
    Display(head);
    return 0;
}