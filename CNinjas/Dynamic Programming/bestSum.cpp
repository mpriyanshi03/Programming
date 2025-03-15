#include <bits/stdc++.h>
using namespace std;

//TABULATION
vector<int> tabu(int target, vector<int> nums){
    vector<vector<int>*> dp(target+1,NULL);
    dp[0]=new vector<int> ();

    for(int i=0;i<=target;i++){
        if(dp[i]!=NULL){
            for(auto it:nums){
                int index=it+i;
                if(index<=target){
                    auto newComb=new vector<int> (*dp[i]);
                    newComb->push_back(it);

                    if(dp[index]==NULL || newComb->size()<dp[index]->size()){
                        dp[index]=newComb;

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
vector<int> memo(int target, vector<int> nums,unordered_map<int,vector<int>> &map){
    if(map.find(target)!=map.end()){
        return map[target];
    }
    if(target==0){
        return {};
    }
    if(target<0)
    {
        return {};
    }
    vector<int> shortest;
    for(auto it : nums){
        int rem=target-it;
        vector<int> result=memo(rem,nums, map);

        if(!result.empty() || rem==0){
            result.push_back(it);
            if(shortest.empty() || result.size()<shortest.size()){
                shortest=result;
            }
            
        }
    }
    map[target]=shortest;
    return map[target];
    
}


//BRUTE FORCE- RECURSION
vector<int> bestSum(int target, vector<int> nums){
    vector<int> shortest;
    if(target==0){
        return {};
    }
    if(target<0)
    {
        return {INT_MAX};
    }

    for(auto it: nums){
        int rem=target-it;

        vector<int> result=bestSum(rem, nums);

        if(!result.empty() || rem==0){
            result.push_back(it);

            if(shortest.empty() || result.size()<shortest.size()){
                shortest=result;
            }
        }
    }

    return shortest;
}

int main(){
    vector<int> numbers = {4,5,8};
    int targetSum =3;
    unordered_map<int,vector<int>> map;

    vector<int> memoans=memo(targetSum, numbers, map);

    //vector<int> result=bestSum(targetSum, numbers);

    vector<int> tabuans=tabu(targetSum,numbers);
    

    if (!tabuans.empty()) {
        for (auto it : tabuans) {
            cout << it << " ";
        }
        cout << endl;
    } else {
        cout << "No combination found" << endl;
    }

    
}

