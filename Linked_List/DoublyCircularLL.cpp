#include <iostream>
using namespace std;

struct Node {
    Node* prev;
    int data;
    Node* next;
};

void Create(Node*& p, int A[], int n) {
    Node* t, * last;
    p = new Node;
    p->data = A[0];
    p->prev = p;
    p->next = p;
    last = p;

    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = p;          // New node points to head (p)
        t->prev = last;       // New node's prev points to the last node
        last->next = t;       // Last node's next points to the new node
        p->prev = t;          // Head's prev points to the new node
        last = t;             // Move last to the new node
    }
}

void Display(Node* p) {
    Node* start = p;
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != start);
    cout << endl;
}

int main() {
    Node* head = NULL;
    int A[] = {10, 20, 30, 40, 50};
    int n = sizeof(A) / sizeof(int);
    Create(head, A, n);
    Display(head);
    return 0;
}
