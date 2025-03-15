#include <bits/stdc++.h>
using namespace std;

//TABULATION
bool tablu(int target, vector<int> &num){
    vector<bool> dp(target+1,false);
    dp[0]=true;

    for(int i=0;i<=target;i++){
        if(dp[i]==true){
            for(auto nums: num){
                if(nums+i<=target){
                    dp[nums+i]=true;
                }   
            }
        }
    }
    return dp[target];
}

//MEMOIZATION
bool memo(int target, vector<int> &num, unordered_map<int,bool> &dp){
    if(dp.find(target)!=dp.end()){
        return dp[target];
        
    }
    if(target==0){
        return true;
    }

    if(target<0){
        return false;
    }

    for(auto it : num){
        int rem=target-it;
        if(memo(rem,num,dp)==true){
            dp[target]=true;
            return true;
        }
        
    }
    dp[target]=false;
    return false;
}

//BRUTE FORCE- RECURSION
bool canSum(int target, vector<int> &num){
    if(target==0){
        return true;
    }

    if(target<0){
        return false;
    }

    for(auto &it : num){
        int diff=target-it;

        if(canSum(diff,num)==true){
            return true;
        }
    }
    return false;
}


int main(){
    int n;
    cout<<"Size of Array"<<endl;
    cin>>n;
    vector<int> num(n);
    int target;
    cout<<"What's the target"<<endl;
    cin>> target;

    cout<<"Give the vector"<<endl;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    unordered_map<int,bool> dp;
    

    //cout<< canSum(target,num)<<endl;
    cout<<tablu(target,num)<<endl;
    cout<<memo(target, num, dp);

}