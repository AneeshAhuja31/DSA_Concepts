#include <iostream>
using namespace std;

struct Node {
    Node* prev;
    int data;
    Node* next;
} *head = NULL;

void Create(Node*& p, int A[], int n) {
    Node* t, * last;
    int i;
    p = new Node;
    p->data = A[0];
    p->prev = p->next = NULL;
    last = p;

    for (i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Reverse(Node*p) {
    Node* temp;
    while (p != nullptr) {
        temp = p->next;  
        p->next = p->prev;  
        p->prev = temp;  
        p=p->prev;
        if(p!=NULL && p->next==NULL)
            head=p;  
    }
}

void Display(Node* p) {
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int A[] = {10, 20, 30, 40, 50};
    int n = sizeof(A) / sizeof(int);
    Create(head, A, n);
    Reverse(head);
    Display(head);
    return 0;
}
