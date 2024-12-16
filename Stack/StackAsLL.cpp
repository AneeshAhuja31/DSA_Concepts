#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
} *top = NULL;

void push(int x) {
    Node* t = new Node;
    if (t == NULL)
        cout << "Stack is Full\n";
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop() {
    Node* t;
    int x = -1;
    if (top == NULL)
        cout << "Stack is Empty\n";
    else {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void Display() {
    Node* p = top;
    while (p != NULL) {
        cout << p->data << " "; // Print the data
        p = p->next;            // Move to the next node
    }
    cout << endl; // Print a newline at the end of the display
}

int main() {
    push(10);
    push(20);
    push(30);
    Display();             // Output: 30 20 10
    cout << pop() << endl; // Output: 30 (followed by a newline)
    Display();             // Output: 20 10
    return 0;
}
