#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> vec={4,2,9,8,2,12,7,12,10,5,8,5,5,7,9,2,5,11};
    sort(vec.begin(),vec.end());
    for(auto i:vec){
        cout<<i<<" ";
    }

}