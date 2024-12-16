#include<iostream>
#include<list>
using namespace std;

void Createlist1(list<int> &lst){
    int A[7] = {1,2,3,4,4,5,6};
    for(int i = 0; i < 7; i++){
        lst.push_back(A[i]); // Add elements to the list
    }
}

void Createlist2(list<int> &lst){
    list<int> :: iterator it;
    int i=0;
    int A[7] = {6,7,8,9,10,11,12};
    for(it = lst.begin();it!=lst.end();it++){
        *it = A[i++];
    }
    
}
void Display(list<int> &lst){
    list<int> :: iterator it;
    for(it=lst.begin();it!=lst.end();it++){
        cout<<*it<<" "; //iteration acts as a pointer
    }
    cout<<endl;
}
int main(){
    list<int> list1; //List of size 0
    list<int> list2(7); //Empty list of size 7
    Createlist1(list1);
    Display(list1);

    list1.pop_front(); 
    list1.pop_back();
    list1.remove(4); //Remove all occurance of 4
    Display(list1);

    list1.sort();
    Display(list1);

    Createlist2(list2);
    list1.merge(list2);
    Display(list1);

    list1.reverse();
    Display(list1);
    return 0;
}