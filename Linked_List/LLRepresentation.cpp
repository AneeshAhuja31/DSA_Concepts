#include<iostream>
using namespace std;
struct Node{
    int data;
    Node*next;
}*head=NULL;  //declaring global pointer (head)

void Create(int A[],int n){
    Node*t,*last;  //t is a temporary pointer
    head = new Node; // first node(head)
    head->data = A[0]; //assign first element of array to head
    head->next=NULL;  //next pointer of head is initially NULL
    last = head; //last pointer points to head initially

    for(int i=1;i<n;i++){
        t = new Node; //create a new node
        t->data=A[i]; //assign data to the new node
        t->next=NULL; //set the next pointer of the new node to NULL
        last->next=t; //link the previous node to the new node
        last = t; //move the last pointer to the newly created node
    }
}
//Traversal
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
    Display(head);
    return 0;
}