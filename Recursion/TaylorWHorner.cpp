#include <iostream>
using namespace std;
float e(float x,float n){
    static float s = 1;
    if(n==0)
        return s;
    s=1+((x/n)*s);
    return e(x,n-1);
}
int main() {
    float a = e(1,100);
    cout<<a;

    return 0;
}