#include <bits/stdc++.h>
using namespace std;

//TABULATION
long long tabu(int n, int m){
    
    vector<vector<long long>> dp(n+1, vector<long long>(m+1,0));

    dp[1][1]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            long long current=dp[i][j];
            if(j+1<=m){
                dp[i][j+1]+=current;
            }
            if(i+1<=n){
                dp[i+1][j]+=current;
            }
        }
    }
    return dp[n][m];

}


//MEMOIZATION
long long gridmemo(int n, int m, vector<vector<long long>> &dp){
    if(n==0 ||m==0){
        dp[n][m]=0;
    }
    if(n==1 || m==1){
        dp[n][m]=1;
    }
    if(dp[n][m]==-1){
        dp[n][m]=gridmemo(n-1,m,dp)+gridmemo(n,m-1,dp);
    }
    return dp[n][m];
}

//BRUTE FORCE
int gridtraveller(int n, int m){
    if(n==0 || m==0){
        return 0;
    }
    if(n==1 || m==1){
        return 1;
    }
    return gridtraveller(n-1, m)+ gridtraveller(n, m-1);
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<long long>> dp(n+1, vector<long long>(m+1,-1));
    
    cout<<tabu(n,m)<<endl;
    cout<<gridmemo(n,m,dp)<<endl;

    
    //cout<<gridtraveller(1,1)<<endl;
    //cout<<gridtraveller(3,1)<<endl;
    //cout<<gridtraveller(3,3)<<endl;
    
    //cout<<gridtraveller(18,18)<<endl;


}