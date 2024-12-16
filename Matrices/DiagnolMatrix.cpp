#include<iostream>
using namespace std;
struct Matrix{
    int A[10];
    int n;
};
void SetDiagnolMatrix(Matrix*m,int i,int j,int x){
    if(i==j)
        m->A[i-1]=x;
}
int Get(Matrix m,int i,int j){
    if(i==j)
        return m.A[i-1];
    else 
        return 0;
}
void Display(Matrix m){
    for(int i=0;i<m.n;i++){
        for(int j=0;j<m.n;j++){
            if(i==j)
                cout<<m.A[i]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }

}

int main(){
    Matrix m;
    m.n=4;
    SetDiagnolMatrix(&m,1,1,5);
    SetDiagnolMatrix(&m,2,2,8);
    SetDiagnolMatrix(&m,3,3,9);
    SetDiagnolMatrix(&m,4,4,12);
    Display(m);
    return 0;
}