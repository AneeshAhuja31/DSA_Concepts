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
void ReverseElements(Node*p){
    Node*q = p;
    int i=0;
    int A[10];
    while(q!=NULL){
        A[i]=q->data;
        q=q->next; 
        i++;
    }
    q=p;
    i--;
    while(q!=NULL){
        q->data=A[i--];
        q=q->next;
    }
}
Node* ReverseLinks(Node*p){
    Node*q=NULL;
    Node*r=NULL;
    while(p!=NULL){
        r=q;  //p,q,r are sliding pointers 
        q=p;
        p=p->next;
        q->next=r;  //Reversing links
    }
    return q;
}
void RecursiveReverse(Node*q,Node*p){
    if(p!=NULL){
        RecursiveReverse(p,p->next);
        p->next=q;
    }
    else
        head = q;
}

void Display(Node*p){
    while(p != NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}
int main(){
    int A[] = {3, 5, 7, 10, 15};
    int n = sizeof(A)/sizeof(int);
    Create(A, n);
    //ReverseElements(head);
    //Display(head);
    head = ReverseLinks(head);
    Display(head);
    //RecursiveReverse(NULL,head);
    //Display(head);
    return 0;
}