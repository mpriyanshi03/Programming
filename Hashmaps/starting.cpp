#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string,int> m;

    //INSERTION
    pair<string,int> p=make_pair("mera",1);
    m.insert(p);
    //OR
    pair<string,int> q("naam",2);
    m.insert(q);

    //OR
    m["love"]=3;

    //SEARCH
    cout<<m["mera"]<<endl;
    cout<<m.at("naam")<<endl;
    cout<<m["Ritu"]<<endl;
    cout<<m.at("Ritu")<<endl;
    //cout<<m["Rizz"]<<endl;

    //SIZE
    cout<<"Size: "<<m.size()<<endl;

    //TO CHECK PRESENCE
    cout<<"Present: "<<m.count("friz")<<endl;

    //ERASE
    m.erase("Ritu");
    cout<<"Size: "<<m.size()<<endl;

    //TRAVERSE
    for(auto i : m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    //OR
    unordered_map<string,int> :: iterator it=m.begin();
    while(it!=m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }


}