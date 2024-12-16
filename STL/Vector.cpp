#include<iostream>
#include <vector>
using namespace std;

void display(vector<int>&v){
    for(int i=0;i<v.size();i++)
        cout<<v.at(i)<<" "; //v.at(i) is basically v[i] 
    cout<<endl;
}
int main(){
    vector<int> vec1; //zero element integer vector
    vector<char> vec2(4); //4 element char vector
    vector<char> vec3(vec2); //4 element char vector from vec2
    vector<int> vec4(6,3); //6 element vector of 3s
    int element,size;
    cout<<"Enter size of your vector: ";
    cin>>size;
    cout<<"\nEnter elements to add to this vector: "; 
    for(int i=0;i<size;i++){
        cin>>element;
        vec1.push_back(element);
    }
    vec1.pop_back();
    display(vec1);
    vector<int> :: iterator iter = vec1.begin(); //iterator is set to first position of vector
    vec1.insert(iter+1,5,566); //5 copies of 566
    display(vec1);
    return 0;
}