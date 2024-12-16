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

struct Stack{
    int size;
    int top;
    Node**S;
};
void StackCreate(Stack*st,int size){
    st->size=size;
    st->top=-1;
    st->S = new Node*[st->size];
}
void push(Stack*st,Node*x){
    if(st->top==st->size-1)
        cout<<"Stack Overflow\n";
    else{
        st->top++;
        st->S[st->top]=x;
    }
}
Node*pop(Stack*st){
    Node*x=NULL;
    if(st->top==-1)
        cout<<"Stack Underflow\n";
    else{
        x=st->S[st->top--];
    }
    return x;
}


bool isEmptyStack(const Stack& st) {
    return st.top == -1;
}
bool isFullStack(const Stack& st) {
    return st.top == st.size - 1;
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
void IPreorder(Node*p){
    Stack*st = new Stack;
    StackCreate(st,100);
    while(p||!isEmptyStack(*st)){
        if(p){
            cout<<p->data<<" ";
            push(st,p);
            p=p->lchild;
        }
        else{
            p=pop(st);
            p=p->rchild;
        }
    }
}
void IInorder(Node*p){
    Stack*st = new Stack;
    StackCreate(st,100);
    while(p||!isEmptyStack(*st)){
        if(p){
            push(st,p);
            p=p->lchild;
        }
        else{
            p=pop(st);
            cout<<p->data<<" ";
            p=p->rchild;
        }
    }
}

int main(){
    CreateTree();
    cout<<"Iterative Preorder: ";
    IPreorder(root);
    cout<<"\nIterative Inorder: ";
    IInorder(root);
}