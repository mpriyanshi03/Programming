#include <bits/stdc++.h>
using namespace std;

//TABULATION
bool tabu(vector<int> &arr, int sum, int n){
    vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));

    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j){
                dp[i][j]=(dp[i-1][j-arr[i-1]]) || (dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];

}

//MEMOIZATION
bool memo(vector<int> &arr, int sum, int n,vector<vector<int>> &dp){

    if(sum==0){
        return true;
    }
    if(n==0 && sum!=0){
        return false;
    }
    if(dp[n][sum]!=-1){
        return dp[n][sum];
    }
    if(arr[n-1]<=sum){
        dp[n][sum]=(memo(arr,sum-arr[n-1], n-1,dp) || memo(arr,sum,n-1,dp));
    }
    else{
        dp[n][sum]=memo(arr,sum,n-1,dp);
    }
    return dp[n][sum];
    
}


//RECURSION
bool recur(vector<int> &arr, int sum, int n){
    if(sum==0){
        return true;
    }
    if(n==0 && sum!=0){
        return false;
    }
    if(arr[n-1]<=sum){
        return (recur(arr,sum-arr[n-1], n-1) || recur(arr,sum,n-1));
    }
    else{
        return recur(arr,sum,n-1);
    }

}

bool subset(vector<int> &arr){
    int n=arr.size();
    if(n==0) return false;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    
    if(sum%2 !=0) return false;
    int target=sum/2;
    vector<vector<int>> dp(n+1,vector<int>(target+1,-1));

    return tabu(arr,target,n);
    //return memo(arr,target,n,dp);
    //return recur(arr,sum/2,n);
    
}

int main() {
    vector<int> arr = {1,3,9,5,12};
    cout << (subset(arr) ? "True" : "False");
    return 0;
}