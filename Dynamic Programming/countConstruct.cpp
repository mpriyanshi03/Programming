#include <bits/stdc++.h>
using namespace std;

//TABULATION
int tabu(string target, vector<string> &array){
    vector<int> dp(target.length()+1,0);
    dp[0]=1;
    for(int i=0;i<=target.length();i++){
        if(dp[i]!=0){
            for(auto words: array){
                if(target.substr(i,words.length())==words){
                    dp[i+words.length()]+=dp[i];
                }

            }
        }
    }
    return dp[target.length()];
}

//MEMOIZATION
int memo(string target, vector<string> array, unordered_map<string,int>& map){

    if(map.find(target)!=map.end()){
        return map[target];
    }
    if(target==""){
            return 1;
        }

        int count=0;
        for(auto words:array){
            if(target.find(words)==0){
                string s=target.substr(words.length());
                int countways=memo(s,array,map);
                count+=countways;
            }
        }
        map[target]=count;
        return count;
}

//BRUTE FORCE-2
    int countconstruct2(string target, vector<string> array){
        if(target==""){
            return 1;
        }

        int count=0;
        for(auto words:array){
            if(target.find(words)==0){
                string s=target.substr(words.length());
                int countways=countconstruct2(s,array);
                count+=countways;
            }
        }
        return count;
    }


//BRUTE FORCE
    int countconstruct(string target, vector<string> array, int &count){
        if(target==""){
            count++;

        }
        for(auto words:array){
            if(target.find(words)==0){
                string s=target.substr(words.length());
                countconstruct(s,array,count);
            }
        }
        return count;
    }

int main(){
    string s;
    cin>>s;

    unordered_map<string, int> map;
    int count=0;
    //vector<string> array={"purp","p","le","ur","purpl"};
    //vector<string> array={"abcd","ab","abc","def","cd"};
    //vector<string> array={"a","p","ent","enter","ot","o","t"};
    vector<string> array={"bo","rd","ate","t","ska","sk","boar"};
    //vector<string> array={"e","ee","eee","eeeeee","ff"};
   
    
    cout<<tabu(s,array)<<endl;
    cout<<memo(s,array,map)<<endl;
    cout<<countconstruct(s,array,count)<<endl;
    cout<<countconstruct2(s,array)<<endl;
    
    
}