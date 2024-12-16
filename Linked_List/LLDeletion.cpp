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

void DeleteNode1(int target) {
    Node *p = head, *t = nullptr;

    // If the head node is the one to be deleted
    if (p != nullptr && p->data == target) {
        head = p->next; // Move head to the next node
        delete p;       // Delete old head
        
    }

    // Traverse the list to find the node to delete
    while (p != nullptr && p->data != target) {
        t = p;          // Move `t` to `p`
        p = p->next;    // Move `p` to the next node
    }

    // If the node was found
    if (p != nullptr) {
        t->next = p->next; // Bypass the node to be deleted
        delete p;          // Delete the node
    }
}

//DELETE AT A SPECIFIC POSITION
int DeleteNode2(int pos){
    Node*p,*q;
    int x=-1;
    //If Node is at head
    if(pos==0){
        x=head->data;
        p = head;
        head = head->next;
        delete p;
    }
    else{
        p=head;
        q=NULL;
        //Traversing the list to find the node at specific index
        for(int i=0;i<pos-1 &&p;i++){
            q=p;
            p=p->next;
        }
        if(p){
            q->next = p->next;
            x = p->data;
            delete p;
        }
    }
    return x;
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
    DeleteNode1(7);
    int pos = 0;
    cout<<"Deleted node at "<<pos<<" which is "<<DeleteNode2(pos)<<endl;
    Display(head);
    return 0;
}