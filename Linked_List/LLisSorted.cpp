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

bool LLisSorted(Node*p){
    int x=-1;
    while(p!=NULL){
        if(x<=p->data){
            x=p->data;
            p=p->next;
        }
        else{
            return false;
        }
    }
    return true;
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
    bool x = LLisSorted(head);
    cout<<"The Linked List is sorted: "<<x;
    
    return 0;
}