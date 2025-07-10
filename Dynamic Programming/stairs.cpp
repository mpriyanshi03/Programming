#include <bits/stdc++.h> 
using namespace std;
const int MOD=1e9+7;
int solve(int n, vector<int> &dp){
    if(n==0 || n==1){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    //return dp[n]=solve(int n)
    return dp[n]=(solve(n-1,dp)+solve(n-2,dp))%MOD;
}
int countDistinctWays(int nStairs) {
    //  Write your code here.
    vector<int> dp(nStairs+1,-1);
    return solve(nStairs,dp);
    
}

int main(){
    int n;
    cin>>n;
    cout<< countDistinctWays(n)<<endl;
}