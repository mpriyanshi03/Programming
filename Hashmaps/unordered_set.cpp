#include<bits/stdc++.h>
using namespace std;

int main(){
    int x=0^5;
    cout<< x <<endl;
    unordered_set<string> st;
    st.insert("a");
    st.insert("ab");
    st.insert("p");
    st.insert("aw");
    st.insert("ap");
    st.insert("ap");

    for(auto it=st.begin();it!=st.end();it++){
        cout<<(*it)<<endl;

    }
    //SIZE
    cout<<"Size: "<< st.size()<<endl;

    string v="p";
    if(st.find(v)!=st.end()){
        cout<<"Key found"<<endl;
        //s.erase(key);
    }
    else{
        cout<<"Not Found"<<endl;
    }








    unordered_set<int> s;
    s.insert(100);
    s.insert(10);
    s.insert(50);
    s.insert(70);
    s.insert(60);
    s.insert(80);
    s.insert(30);

    for(auto it=s.begin();it!=s.end();it++){
        cout<<(*it)<<endl;
    }
    //SIZE
    cout<<"Size: "<< s.size()<<endl;

    //FIND
    int key=70;
    if(s.find(key)!=s.end()){
        cout<<"Key found"<<endl;
        //s.erase(key);
    }
    else{
        cout<<"Not Found"<<endl;
    }
    cout<<"Size: "<< s.size()<<endl;
    cout<<s.count(key)<<endl;



}