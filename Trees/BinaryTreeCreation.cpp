#include<iostream>
#include"Queue+Node.h"
using namespace std;

Node*root=NULL;

void CreateTree(){
    Node*p,*t;
    int x;
    Queue q;
    CreateQueue(&q,100); // from header file

    cout<<"Enter root value ";
    cin>>x;
    root = new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);

    while(!isEmptyQueue(q)){
        p=dequeue(&q);
        cout<<"Enter left child of "<<p->data<<": ";
        cin>>x;
        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q,t);
        }
        cout<<"Enter right child of "<<p->data<<": ";
        cin>>x;
        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q,t);
        }
    }
}

void preorder(Node*p){
    if(p){
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(Node*p){
    if(p){
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}

void postorder(Node*p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

int main(){
    CreateTree();
    cout<<"Preorder: ";
    preorder(root);
    cout<<"\nInorder: ";
    inorder(root);
    cout<<"\nPostorder: ";
    postorder(root);
    return 0;
}