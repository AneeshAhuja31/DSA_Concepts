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
void DeleteNode(int target) {
    Node *p = head, *t = nullptr;

    if (p != nullptr && p->data == target) {
        head = p->next; 
        delete p;       
        
    }

    while (p != nullptr && p->data != target) {
        t = p;          
        p = p->next;    
    }

    if (p != nullptr) {
        t->next = p->next; 
        delete p;          
    }
}

void RemoveDuplicates(Node*p){
    int H[100]={0};
    int i=0;
    while(p!=NULL){
        i = p->data;
        H[i]++;
        p=p->next;
    }
    for(int j=0;j<=100;j++){
        while(H[j]>1){
            DeleteNode(j);
            H[j]--;
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
    int A[] = {3,3,3, 5, 7, 7, 10, 15, 15};
    int n = sizeof(A)/sizeof(int);
    Create(A, n);
    RemoveDuplicates(head);
    Display(head);
    return 0;
}