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
Sparse *add(Sparse*s1,Sparse*s2){
    Sparse*sum = new Sparse;
    sum->e= new Element[s1->num+s2->num];
    int i=0,j=0,k=0;
    while(i<s1->num && j<s2->num){
        if(s1->e[i].i<s2->e[j].i)
            sum->e[k++]=s1->e[i++];
        else if(s1->e[i].i>s2->e[j].i)
            sum->e[k++]=s2->e[j++];
        else{
            if(s1->e[i].j<s2->e[j].j)
                sum->e[k++]=s1->e[i++];
            else if(s1->e[i].j>s2->e[j].j)
                sum->e[k++]=s2->e[j++];
            else{
                sum->e[k]=s1->e[i];
                sum->e[k++].x = s1->e[i++].x + s2->e[j++].x;
            }
        }
    }
    for(;i<s1->num;i++) sum->e[k++] = s1->e[i]; //Assigning Remaining Elements after comparision
    for(;j<s2->num;j++) sum->e[k++] = s2->e[j];

    sum->m = s1->m; //Assingning Dimensions
    sum->n = s1->n;
    sum->num = k; //Assingning Non Zero Elements

    return sum;
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
    Sparse s1,s2,*s3;
    Create(&s1);
    Create(&s2);
    s3 = add(&s1,&s2);
    cout<<"\nFirst Matrix\n";
    Display(s1);
    cout<<"\nSeoond Matrix\n";
    Display(s2);
    cout<<"\nSum Matrix\n";
    Display(*s3);
    return 0;
}