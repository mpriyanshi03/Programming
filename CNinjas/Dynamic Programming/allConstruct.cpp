#include <bits/stdc++.h>
using namespace std;
//TABULATION
vector<vector<string>> tabu(string s, vector<string> &array)
{
    vector<vector<vector<string>>>dp(s.length()+1);
    dp[0]={{}};

    for(int i=0;i<=s.length();i++){
        for(auto word : array){
            if(!dp[i].empty()){
                if(s.substr(i,word.length())==word){
                    vector<vector<string>> newCombinations;

                    for(auto it : dp[i]){
                        vector<string> comb=it;
                        comb.push_back(word);
                        dp[i+word.length()].push_back(comb);
                    }
                }
            }
            
        }
    }
    return dp[s.length()];


}

//MEMOIZATION
vector<vector<string>> memo(string s, vector<string> &array, unordered_map<string, vector<vector<string>>>& map){

    if(map.find(s)!=map.end()){
        return map[s];
    }
    vector<vector<string>> output;

    if(s==""){
        return {{}};
    }
    for(auto word : array){
        if(s.find(word)==0){
            string suffix=s.substr(word.length());
            vector<vector<string>> suffixWay=memo(suffix,array,map);

            for(auto& ways : suffixWay){
                ways.push_back(word);
                reverse(ways.begin(),ways.end());
                output.push_back(ways);
            }
        }
    }
    map[s]=output;
    return output;

}

//BRUTE FORCE
vector<vector<string>> allConstruct(string s, vector<string> array){
    vector<vector<string>> output;
    //vector<string> ans;

    if(s==""){
        return {{}};
    }
    for(auto word : array){
        if(s.find(word)==0){
            string suffix=s.substr(word.length());
            vector<vector<string>> suffixWay=allConstruct(suffix,array);

            for(auto& ways : suffixWay){
                ways.push_back(word);
                reverse(ways.begin(),ways.end());
                output.push_back(ways);
            }
        }
    }
    return output;

}

void printResult(const vector<vector<string>>& result) {
    for (const auto& way : result) {
        for (const auto& word : way) {
            cout << word << " ";
        }
        cout << endl;
    }
}

int main(){
    string s;
    cin>>s;

    unordered_map<string, vector<vector<string>>> map;
    
    //vector<string> array={"purp","p","le","ur","purpl"};
    vector<string> array={"abcd","ab","abc","def","cd"};
    //vector<string> array={"a","p","ent","enter","ot","o","t"};
    //vector<string> array={"bo","rd","ate","t","ska","sk","boar"};
    //vector<string> array={"e","ee","eee","eeeeee","ff"};
    //vector<string> array={"aa","aaa","a","aaaaaaa","aaaa"};

    vector<vector<string>> tabuans=tabu(s,array);
    printResult(tabuans);

    
    vector<vector<string>> ansmemo=memo(s,array,map);
    printResult(ansmemo);

    //vector<vector<string>> result=allConstruct(s,array);
    //printResult(result);

}