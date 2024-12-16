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

int isOperator(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^')
        return 1;
    else
        return 0;
}
int isParenthesis(char x){
    if(x=='('||x==')')
        return 1;
    else
        return 0;
}

int OutStackPre(char x){
    if(x=='+'||x=='-')
        return 1;
    else if(x=='*'||x=='/')
        return 3;
    else if(x=='^')
        return 6;
    else if(x=='(')
        return 7;
    else if(x==')')
        return 0;
}
int InStackPre(char x){
    if(x=='+'||x=='-')
        return 2;
    else if(x=='*'||x=='/')
        return 4;
    else if(x=='^')
        return 5;
    else if(x=='(')
        return 0;
    else if(x==')')
        return 0;
}

char*Convert(char*infix){
    Stack *st = new Stack;
    int len = strlen(infix)+1;
    Create(st,len);
    char*postfix = new char[len]; 
    int i=0,j=0;
    while(infix[i]!='\0'){
        if(isOperator(infix[i])){
            while(OutStackPre(infix[i])<=InStackPre(stacktop(st)) && (!isEmpty(st)))
                postfix[j++]=pop(st);
            push(st,infix[i++]);
        }
        else if(isParenthesis(infix[i])){
            if(infix[i]=='(')
                push(st,infix[i++]);
            else{
                while(stacktop(st)!='(')
                    postfix[j++]=pop(st);
                pop(st);
                i++;
            }
        }
        
        else{ 
            postfix[j++]=infix[i++];
        }
    }
    //to copy operator left in stack to postfix
    while(!isEmpty(st)){
        postfix[j++]=pop(st);
    }
    postfix[j]='\0';

    return postfix;
}

int main(){
    char A[] ="((a+b)*c)-d^e^f";
    char *B=Convert(A);
    cout<<B;
}