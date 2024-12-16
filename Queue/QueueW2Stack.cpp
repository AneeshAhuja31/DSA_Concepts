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
void enqueue(Stack*s1,int x){
    push(s1,x);
}
int dequeue(Stack*s1,Stack*s2){
    int x=-1;
    if(isEmpty(s1)){
        cout<<"Queue is Empty";
        return x;
    }
    else{
        while(!isEmpty(s1))
            push(s2,pop(s1));
        int y= pop(s2);
        while(!isEmpty(s2))
            push(s1,pop(s2));
        return y;
    }
}
void Display(Stack st){
    for(int i=st.top;i>=0;i--){
        cout<<st.s[i]<<" ";}
    cout<<endl;
}
int main(){
    Stack *s1=new Stack,*s2=new Stack;
    Create(s1);
    Create(s2);
    enqueue(s1,1);
    enqueue(s1,2);
    enqueue(s1,3);
    enqueue(s1,4);
    enqueue(s1,5);
    dequeue(s1,s2);
    Display(*s1);
}