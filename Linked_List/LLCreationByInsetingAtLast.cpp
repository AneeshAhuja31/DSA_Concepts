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
void InsertLast(int x){
    Node*last,*t; 
    
    t=new Node;
    t->data = x;
    t->next = NULL;
    
    if(head==NULL)
        head = last = t;
    else{
        last->next =t;
        last = t;
    }
}

void Display(Node*p){
    while(p != NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
}
int main(){
    //int A[] = {3, 5, 7, 10, 15};
    //int n = sizeof(A)/sizeof(int);
    //Create(A, n);
    InsertLast(1);
    InsertLast(2);
    InsertLast(3);
    InsertLast(4);
    Display(head);
    return 0;
}