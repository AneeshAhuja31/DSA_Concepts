#include<iostream>
using namespace std;
struct Element{
    int i;
    int j;
    int x;
};
struct Sparse{
    int m;
    int n;
    int num;
    Element *e;
};
void Create(Sparse*s){
    cout<<"Enter the Dimensions: ";
    cin>>s->m>>s->n;
    cout<<"\nEnter number of non zero elements: ";
    cin>>s->num;
    s->e=new Element[s->num];
    cout<<"\nEnter non zero elements";
    for(int a=0;a<s->num;a++){
        cin>>s->e[a].i>>s->e[a].j>>s->e[a].x;
    }
}
void Display(Sparse s){
    int k=0;
    for(int i=0;i<s.m;i++){
        for(int j=0;j<s.n;j++){
            if(i==s.e[k].i && j==s.e[k].j)
                cout<<s.e[k++].x;
            else
                cout<<" 0 ";
        }
        cout<<endl;
    }
}
int main(){
    Sparse s;
    Create(&s);
    Display(s);
    return 0;
}