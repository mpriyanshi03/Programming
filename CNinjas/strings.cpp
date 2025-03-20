#include <bits/stdc++.h>
using namespace std;


int main(){
    string s="dog cat cat fish";
    vector<string> vec;
    stringstream ss(s);
    string word;
    while(ss>>word){
        vec.push_back(word);
    }
    for(auto it : vec){
        cout<<it<<endl;
    }

}