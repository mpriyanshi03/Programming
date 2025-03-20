#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_set<int> s;
    int a1[5]={1,2,3,4,5};
    int a2[3]={1,2,3};

    for(int i=0;i<5;i++){
        s.insert(a1[i]);
        
    }
    for(int i=0;i<3;i++){
        s.insert(a2[i]);
    }
    cout<<s.size();

}