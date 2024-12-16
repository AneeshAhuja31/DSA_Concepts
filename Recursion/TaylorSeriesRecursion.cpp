#include <iostream>
using namespace std;
float fac(int n){
    if(n>0)
        return fac(n-1)*n;
    return 1;
}
float pow(int m,int n){
    if(n>0)
        return pow(m,n-1)*m;
    return 1;
}
float tay_1(int x,int n){
    if(n>=0)
        return tay_1(x,n-1) + (pow(x,n)/fac(n));
    return 0;
}

//ANOTHER WAY:
float tay_2(int x,int n){
    static float p = 1,f = 1;
    float r;
    if(n==0)
        return 1;
    else 
        r = tay_2(x,n-1);
        p = p*x;
        f = f*n;
        return r+(p/f);
}
int main() {
    float a = tay_1(1,100);  // e = 2.71828
    float b = tay_2(1,100); // e = 2.71828

    cout << a << endl << b;
    return 0;
}