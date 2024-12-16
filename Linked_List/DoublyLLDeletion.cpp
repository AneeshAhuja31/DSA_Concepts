#include<iostream>
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

int Delete(Node* &p, int index) {
    Node* curr = p;
    int x;
    if (index == 0) {
        p = curr->next;
        if (p) p->prev = NULL;
        x = curr->data;
        delete curr;
    } else {
        for (int i = 0; i < index; i++) curr = curr->next;
        curr->prev->next = curr->next;
        if (curr->next) curr->next->prev = curr->prev;
        x = curr->data;
        delete curr;
    }
    return x;
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
    int x=Delete(head, 0);
    cout<<"Deleted Element: "<<x<<endl;
    Display(head);
    return 0;
}
