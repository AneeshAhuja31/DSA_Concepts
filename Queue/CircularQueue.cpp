#include <iostream>
using namespace std;

struct Queue {
    int size;
    int front;
    int rear;
    int* Q;
};

void Create(Queue* q, int size) {
    q->size = size;
    q->front = q->rear = 0;
    q->Q = new int[size];
}

void enqueue(Queue* q, int x) {
    if ((q->rear + 1) % q->size == q->front) {
        cout << "Queue is Full" << endl;
    } else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

int dequeue(Queue* q) {
    int x = -1;
    if (q->front == q->rear) {
        cout << "Queue is Empty" << endl;
    } else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void Display(Queue q) {
    int i=q.front+1;
    do{
        cout<<q.Q[i]<<" ";
        i=(i+1)%q.size;
    }
    while(i!=(q.rear+1)%q.size);
    cout << endl;
}


int main() {
    Queue q;
    Create(&q, 5); 
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    dequeue(&q);
    enqueue(&q, 60);
    Display(q);
    
    return 0;
}
