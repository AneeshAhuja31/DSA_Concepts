#include<iostream>
#include <math.h>
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
void Display(Poly p){
    cout<<"The Polynomial is: ";
    for(int i=p.n-1;i>=0;i--){
        cout<<p.t[i].coeff<<"x^"<<p.t[i].exp<<" + ";
    }
    cout<<"0";
}
int Evaluation(Poly p,int x){
    int sum=0;
    for(int i=0;i<p.n;i++)
        sum += p.t[i].coeff*pow(x,p.t[i].exp);
    return sum;
}
Poly*add(Poly*p1,Poly*p2){
    int i=0,j=0,k=0;
    Poly*sum = new Poly;
    sum->t = new Term[p1->n + p2->n];
    
    while(i<p1->n && j<p2->n){
        if(p1->t[i].exp > p2->t[j].exp)
            sum->t[k++] = p1->t[i++];
        else if(p1->t[i].exp < p2->t[j].exp)
            sum->t[k++] = p2->t[j++];
        else{
            sum->t[k++].exp = p1->t[i++].exp;
            sum->t[k++].coeff = p1->t[i++].coeff + p2->t[j++].coeff;
        }
    }
    for(;i<p1->n;i++) sum->t[k++] = p1->t[i]; 
    for(;j<p2->n;j++) sum->t[k++] = p2->t[j];

    sum->n = k;
    return sum;
}
int main(){
    Poly p1;
    int x;
    Create(&p1);
    Create(&p1);
    Display(p1);
    cout<<"\nEnter Number: ";
    cin>>x;
    int ans = Evaluation(p1,x);
    cout<<"The Answer is: "<<ans;
    
    return 0;
}