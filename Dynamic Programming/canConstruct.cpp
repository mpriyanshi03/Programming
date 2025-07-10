#include <bits/stdc++.h>
using namespace std;

//TABULATION
bool tabu(string target, vector<string> &array){
    vector<bool> dp(target.length()+1,false);
    dp[0]=true;

    for(int i=0;i<=target.length();i++){
        if(dp[i]==true){
            for(auto word  : array){
                if(target.substr(i,word.length())==word){
                    dp[i+word.length()]=true;
                }
            }

        }
    }
    return dp[target.length()];

}

//MEMOIZATION
bool memo(string s, vector<string> &array, unordered_map<string,bool> &map){
    if(map.find(s)!=map.end()){
        return map[s];
    }
    if(s==""){
        
        return true;
    }
    for(auto it : array){
        if(s.find(it)==0){
            string sub=s.substr(it.length());
            if(memo(sub, array, map)==true){
                map[s]=true;
                return true;
            }
        }
    }
    map[s]=false;
    return false;
}

//BRUTE FORCE
bool canConstruct(string s, vector<string> &array){

    if(s==""){
        return true;
    }
    for(auto it : array){
        if(s.find(it)==0){
            string sub=s.substr(it.length());
            if(canConstruct(sub, array)==true){
                return true;
            }
        }
    }
    return false;
}

int main(){
    string s;
    cin>>s;
    //vector<string> array={"purp","p","le","ur","purpl"};
    //vector<string> array={"abcd","ab","abc","def","cd"};
    //vector<string> array={"a","p","ent","enter","ot","o","t"};
    
    //vector<string> array={"bo","rd","ate","t","ska","sk","boar"};
    vector<string> array={"e","ee","eeee","eeeeee","eeeeeeee","ffff"};
   
    unordered_map<string, bool> map;
    cout<<tabu(s,array)<<endl;
    cout<<memo(s,array,map)<<endl;
    //cout<< canConstruct(s,array)<<endl;

}