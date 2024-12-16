#include <iostream>
#include<string.h>
using namespace std;

struct Stack {
    int size;
    int top;
    char* s; // Changed to char* to handle character stack
};

void Create(Stack* st, int size) {
    st->size = size;
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
int stacktop(Stack*st){
    if(st->top==-1)
        return -1;
    else
        return st->s[st->top];
}

bool isEmpty(Stack* st) {
    return st->top == -1;
}

int Precedent(char x){
    if(x=='+'||x=='-')
        return 1;
    else if(x=='*'||x=='/')
        return 2;
    if(x>=97 && x<=122 || x>=65 && x<=90)
        return 3;
    return 0;
}

char*Convert(char*infix){
    Stack *st = new Stack;
    int len = strlen(infix)+1;
    Create(st,len);
    char*postfix = new char[len]; 
    int i=0,j=0;
    while(infix[i]!='\0'){
        if(Precedent(infix[i])>Precedent(stacktop(st)))
            push(st,infix[i++]);
        else
            postfix[j++]=pop(st);
    }
    //to copy operator left in stack to postfix
    while(!isEmpty(st)){
        postfix[j++]=pop(st);
    }
    postfix[j]='\0';

    return postfix;
}

int main(){
    char A[] ="A+B*C-D/E";
    char *B=Convert(A);
    cout<<B;
}