#include<iostream>
using namespace std;
struct Term{
    int coeff;
    int exp;
};
struct Poly{
    int n;
    Term *t;
};

void Create(Poly *p){
    cout<<"Number of non zero terms: ";
    cin>>p->n;
    p->t = new Term[p->n];
    cout<<"Enter polynomial terms: ";
    for(int i=0;i<p->n;i++){
        cout<<"Term number "<<i+1<<": ";
        cin>>p->t[i].coeff>>p->t[i].exp;

    }
}

Poly*Add(Poly*p1,Poly*p2){
    int i=0,j=0,k=0;
    Poly*sum = new Poly;
    sum->t = new Term[p1->n + p2->n];
    
    while(i<p1->n && j<p2->n){
        if(p1->t[i].exp > p2->t[j].exp)
            sum->t[k++] = p1->t[i++];
        else if(p1->t[i].exp < p2->t[j].exp)
            sum->t[k++] = p2->t[j++];
        else{
            sum->t[k].exp = p1->t[i].exp;
            sum->t[k++].coeff = p1->t[i++].coeff + p2->t[j++].coeff;
        }
    }
    for(;i<p1->n;i++) sum->t[k++] = p1->t[i]; 
    for(;j<p2->n;j++) sum->t[k++] = p2->t[j];

    sum->n = k;
    return sum;
}
void Display(Poly p){
    cout<<"The Polynomial is: ";
    for(int i=p.n-1;i>=0;i--){
        cout<<p.t[i].coeff<<"x^"<<p.t[i].exp<<" + ";
    }
    cout<<"0";
}

int main(){
    Poly p1,p2,*sum;
    
    Create(&p1);
    Create(&p2);
    sum = Add(&p1,&p2);
    Display(p1);
    Display(p2);
    Display(*sum);
    

    
    
    
    return 0;
}