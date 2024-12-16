#include <iostream>
using namespace std;
int power(int m, int n){
    if(n>0)
        return power(m,n-1)*m;
    return 1;
}
int main() {
    int x = power(2,9);
    cout<<x;
    return 0;
}