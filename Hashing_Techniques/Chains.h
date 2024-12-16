#include<iostream>
using namespace std;
struct Node{
    int data;
    Node*next;
};

void SortedInsert(Node**H,int x){
    Node*t,*q=NULL,*p=*H;
    t = new Node;
    t->data=x;
    t->next=NULL;
    if(*H==NULL) *H=t;
    else{
        while(p&&p->data<x){
            q=p;
            p=p->next;
        }
        if(p==*H){
            t->next=q->next;
            q->next=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }
    }
}
Node*Search(Node*p,int key){
    while(p){
        if(key==p->data) return p;
        p=p->next;
    }
    return NULL;
}