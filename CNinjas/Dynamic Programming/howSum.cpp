#include <bits/stdc++.h>
using namespace std;

//TABULATION
vector<int> tabu(int target,vector<int> arr){
    vector<vector<int>*> dp(target+1, NULL);
    dp[0]=new vector<int> ();
    for(int i=0;i<=target;i++){
        if(dp[i]!=NULL){
            for(auto nums: arr){
                if(i+nums<=target)
                {
                    if( dp[i+nums]==NULL){
                        dp[i+nums]=new vector<int> (*dp[i]);
                        dp[i+nums]->push_back(nums);

                    }
                    
                }

            }

        }
        
    }
    vector<int> result;
    if(dp[target]!=NULL){
        result= *dp[target];
    }
    

    for (auto vec : dp) {
        delete vec;
    }
    return result;

}


//MEMOIZATION
vector<int> memo(int target, vector<int> arr, vector<int> &newarr,unordered_map<int,vector<int>> &map){
    if(map.find(target)!=map.end()){
        return map[target];
    }
    if(target==0){
        return newarr;   
    }

    if(target<0){
        return {};
    }
    for(auto it: arr){
        int rem=target-it;
        newarr.push_back(it);

        vector<int> result=memo(rem,arr,newarr,map);

        if(!result.empty()){
            map[target]= result;
            return map[target];
        }
        newarr.pop_back();
    }
    map[target]={};
    return {};

}

//BRUTE FORCE
vector<int> solve(int target, vector<int> arr, vector<int> &newarr){
    if(target==0){
        return newarr;
    }
    if(target<0){
        return {};
    }
    for(auto it: arr){
        int rem=target-it;
        newarr.push_back(it);

        vector<int> result=solve(rem, arr, newarr);

        if(!result.empty()){
            return result;
            
        }
        newarr.pop_back();
        
    }
    return {};
}

int main(){
    unordered_map<int,vector<int>> map;
    vector<int> arr={7,14};

    //vector<int> newarr={};
    //memo(7,arr,newarr,map);

    vector<int> ans=tabu(300,arr);

    //solve(7, arr, newarr);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }


}