#include <iostream>
using namespace std;

struct Stack {
    int size;
    int top;
    char* s; // Changed to char* to handle character stack
};

void Create(Stack* st) {
    cout << "Enter size of stack: ";
    cin >> st->size;
    st->top = -1;
    st->s = new char[st->size]; // Allocate memory for character stack
}

void push(Stack* st, char x) {
    if (st->top == st->size - 1)
        cout << "Stack Overflow\n";
    else {
        st->s[++st->top] = x; // Increment top before assignment
    }
}

char pop(Stack* st) {
    char x = -1;
    if (st->top == -1)
        cout << "Stack Underflow\n";
    else {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

bool isEmpty(Stack* st) {
    return st->top == -1;
}

bool isBalance(char* exp) {
    Stack st;
    Create(&st); // Initialize the stack

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(')
            push(&st, exp[i]);
        else if (exp[i] == ')') {
            if (isEmpty(&st)) {
                delete[] st.s; // Deallocate memory before returning
                return false;
            }
            pop(&st);
        }
    }

    bool balanced = isEmpty(&st);
    delete[] st.s; // Deallocate memory after use
    return balanced;
}

//  ({[)}]}  is also an unbalanced state
bool isBalancePt2(char *exp){
    Stack st;
    Create(&st);
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='['){
            push(&st,exp[i]);
        }
        else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
            if(isEmpty(&st))
                return false;
            char top=pop(&st);
            if(exp[i]==')'&& top!='('||exp[i]=='}'&& top!='{'||exp[i]==']'&& top!='[')
                return false;
        }
    }
    return isEmpty(&st);
}

void Display(Stack st) {
    for (int i = st.top; i >= 0; i--) {
        cout << st.s[i] << " ";
    }
    cout << endl;
}

int main() {
    char exp1[] = "((a+b)*(c-d))";
    char exp2[] = "([a+b{*}c)-d]";
    if (isBalance(exp1))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";
    
    if (isBalancePt2(exp2))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";
    
    return 0;
}
