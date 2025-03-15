#include <bits/stdc++.h>
using namespace std;

//SPACE OPTIMIZATION
long long space(int n)
{
    long long prev1=1;
    long long prev2=0;

    for(int i=2;i<=n;i++){
        long long temp=prev1+prev2;
        prev2=prev1;
        prev1=temp;
    }
    return prev1;
}
//TABULATION
long long fib_tab(long long n, vector<long long> &dp){
    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

//MEMOIZATION
long long fib(long long n, vector<long long> &dp){
    if(n<=1){
        return n;
    }

    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n]=fib(n-1,dp)+fib(n-2, dp);
}

//BRUTE FORCE
int fib(int a){
    if(a<=1){
        return a;
    }
   
    return fib(a-1) + fib(a-2);

    
}

int main(){
    long long n;
    cin>>n;
    vector<long long> dp(n+1,-1);
    //cout<< fib(n)<<endl;
    cout<<space(n)<<endl;
    cout<<fib(n,dp)<<endl;

    cout<<fib_tab(n,dp)<<endl;
    

}