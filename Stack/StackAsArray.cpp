#include<iostream>
using namespace std;
struct Stack{
    int size;
    int top;
    int*s;
};
void Create(Stack*st){
    cout<<"Enter size of stack: ";
    cin>>st->size;
    st->top = -1;
    st->s = new int[st->size]; 
}
void push(Stack*st,int x){
    if(st->top==st->size-1)
        cout<<"Stack Overflow";
        else{
            st->top++;
            st->s[st->top]=x;
        }
}
int pop(Stack*st){
    int x=-1;
    if(st->top==-1)
        cout<<"Stack Underflow";
    else{
        x=st->s[st->top];
        st->top--;
    }
    return x; 
}
int peek(Stack*st,int pos){
    int x=-1;
    int index = st->top-pos+1; 
    if(index <0){
        cout<<"Invalid Position";}
    else{
        x=st->s[index];}
    return x;
}
int stacktop(Stack*st){
    if(st->top==-1)
        return -1;
    else
        return st->s[st->top];
}
int isEmpty(Stack*st){
    if(st->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(Stack*st){
    if(st->top==st->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
void Display(Stack st){
    for(int i=st.top;i>=0;i--){
        cout<<st.s[i]<<" ";}
    cout<<endl;
}
int main(){
    Stack st;
    Create(&st);
    push(&st,100);
    push(&st,200);
    push(&st,300);
    push(&st,400);
    push(&st,500);
    pop(&st);
    Display(st);
    return 0; 
}