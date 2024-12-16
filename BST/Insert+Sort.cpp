#include<iostream>
using namespace std;

struct Node{
    Node*lchild;
    int data;
    Node*rchild;
}*root=NULL;

void Insert(int key){
    Node*t=root;
    Node*r,*p;

    if(root==NULL){
        p = new Node;
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t){
        r=t; //we use r as parent node
        if(key<t->data)
            t=t->lchild;
        else if(key>t->data)
            t=t->rchild;
        else  //when key==t->data
            return; //do nothing
    }
    p = new Node;
    p->data=key;
    p->lchild=p->rchild=NULL;

    //link with parent node
    if(key<r->data) r->lchild=p;
    if(key>r->data) r->rchild=p;
}
Node*RInsert(Node*p,int key){
    Node*t=NULL;
    if(p==NULL){
        t= new Node;
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key<p->data)
        p->lchild=RInsert(p->lchild,key);
    else if(key>p->data)
        p->rchild=RInsert(p->rchild,key);
    return p;
}
Node*Search(int key){
    Node*t=root;
    while(t){
        if(key==t->data)
            return t;
        else if(key<t->data)
            t=t->lchild;
        else
            t=t->rchild;
    }
    return NULL;
}

void Inorder(Node*p){
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}
int main(){
    Insert(10);
    RInsert(root,5);
    Insert(20);
    RInsert(root,8);
    Insert(30);
    Inorder(root);
    Node*temp = Search(20);
    cout<<endl<<temp->data;
    return 0;
}