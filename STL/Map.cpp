#include<iostream>
#include <map>
#include <string>
using namespace std;
//Map is an associative array
int main(){
    map<string,int> marksMap;
    //map will store the string in alphabetical order 
    marksMap["Harry"] = 98;
    marksMap["Jack"] = 59;
    marksMap["Rohan"] = 2;
    marksMap.insert({{"Kozume",10},{"Kuroo",76}});
    map<string,int> :: iterator itr;
    for(itr = marksMap.begin();itr!=marksMap.end();itr++){
        cout<<(*itr).first<<" "<<(*itr).second<<endl; // first = string and second = integer
    }
    return 0;
}