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
