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
    q->front = q->size; // Start at the end for front
    q->rear = 0; // Start at the beginning for rear
    q->Q = new int[size];
}

void enqueue(Queue* q, int x, char c) {
    if (c == 'r') {
        if ((q->rear + 1) % q->size == q->front % q->size) 
            cout << "Queue is Full" << endl;
        else {
            q->Q[q->rear] = x;
            q->rear = (q->rear + 1) % q->size;
        }
    } 
    else if (c == 'f') {
        if ((q->front - 1 + q->size) % q->size == q->rear)
            cout << "Queue is Full" << endl;
        else {
            q->front = (q->front - 1 + q->size) % q->size;
            q->Q[q->front] = x;
        }
    } 
    else
        cout << "Enter either 'f' or 'r'" << endl;
}

int dequeue(Queue* q, char c) {
    int x = -1;
    if (c == 'f') {
        if (q->front == q->rear) 
            cout << "Queue is Empty" << endl;
        else {
            x = q->Q[q->front];
            q->front = (q->front + 1) % q->size;
        }
    } 
    else if (c == 'r') {
        if (q->front == q->rear)
            cout << "Queue is Empty" << endl;
        else {
            q->rear = (q->rear - 1 + q->size) % q->size;
            x = q->Q[q->rear];
        }
    } 
    else
        cout << "Enter either 'f' or 'r'" << endl;
    return x;
}

void Display(Queue q) {
    if (q.front == q.rear) {
        cout << "Queue is Empty" << endl;
        return;
    }

    int i = q.front % q.size;
    while (i != q.rear) {
        cout << q.Q[i] << " ";
        i = (i + 1) % q.size;
    }
    cout << endl;
}

int main() {
    Queue q;
    Create(&q, 5); 
    enqueue(&q, 10, 'r');
    enqueue(&q, 20, 'f');
    enqueue(&q, 30, 'r');
    enqueue(&q, 40, 'r');
    Display(q);
    dequeue(&q, 'f');
    Display(q);
    dequeue(&q, 'r');
    Display(q);
    
    return 0;
}
