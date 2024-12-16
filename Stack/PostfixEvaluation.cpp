#include <iostream>
#include <cstring>
using namespace std;

struct Stack {
    int size;
    int top;
    int* s; // Changed to int* to handle integer stack
};

void Create(Stack* st, int size) {
    st->size = size;
    st->top = -1;
    st->s = new int[st->size]; // Allocate memory for integer stack
}

void push(Stack* st, int x) {
    if (st->top == st->size - 1)
        cout << "Stack Overflow\n";
    else {
        st->s[++st->top] = x; // Increment top before assignment
    }
}

int pop(Stack* st) {
    int x = -1;
    if (st->top == -1)
        cout << "Stack Underflow\n";
    else {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int stacktop(Stack* st) {
    if (st->top == -1)
        return -1;
    else
        return st->s[st->top];
}

bool isEmpty(Stack* st) {
    return st->top == -1;
}

int isOperand(char x) {
    return (x >= '0' && x <= '9'); // Operand is a digit
}

int Eval(char* postfix) {
    Stack st;
    Create(&st, strlen(postfix)); // Allocate memory for the stack
    
    int i, x1, x2, r;
    for (i = 0; postfix[i] != '\0'; i++) {
        if (isOperand(postfix[i])) {
            push(&st, postfix[i] - '0'); // Convert ASCII code to integer
        } else {
            x2 = pop(&st);
            x1 = pop(&st);
            switch (postfix[i]) {
                case '+': r = x1 + x2; break;
                case '-': r = x1 - x2; break;
                case '*': r = x1 * x2; break;
                case '/': r = x1 / x2; break;
            }
            push(&st, r);
        }
    }
    return pop(&st);
}

int main() {
    char* postfix = "234*+82/-";
    
    int result = Eval(postfix);
    cout << "Result of evaluation: " << result << endl;

    return 0;
}
