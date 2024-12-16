#include<iostream>
using namespace std;

struct Node{
    Node*lchild;
    int data;
    Node*rchild;
};
struct Queue{
    int size;
    int front;
    int rear;
    Node**Q; // one * for Node and one * for array
};
void CreateQueue(Queue*q,int size){
    q->size=size;
    q->front=q->rear=-1;
    q->Q = new Node*[q->size];

}
void enqueue(Queue* q, Node* x) {
    if ((q->rear + 1) % q->size == q->front) {
        cout << "Queue is Full" << endl;
    } else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}
Node* dequeue(Queue* q) {
    Node* x = NULL;
    if (q->front == q->rear) {
        cout << "Queue is Empty" << endl;
    } else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

bool isEmptyQueue(const Queue& q) {
    return q.front == q.rear;
}


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

int Count(Node* p) {
    if (p)
        return Count(p->lchild) + Count(p->rchild) + 1;  // Add 1 to count the current node
    return 0;
}


int Height(Node*p){
    int x=0,y=0;
    if(p==0)
        return 0;
    x=Height(p->lchild);
    y=Height(p->rchild);
    if(x>y)
        return x+1;
    else    
        return y+1;
}
int main(){
    CreateTree();
    cout<<endl<<Count(root)<<" "<<Height(root);
    return 0;
}