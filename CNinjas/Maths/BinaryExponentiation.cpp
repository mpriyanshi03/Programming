//An efficient way to calculate large power


#include <bits/stdc++.h>
using namespace std;

//RECURSIVE WAY

int MOD=1e9+7;
long long findpower(long long a, long long b){
    if(b==0) return 1;

    long long half= findpower(a, b/2);

    long long value=(half%MOD*half%MOD)%MOD;
    if(b%2==1){
        return (a%MOD*value%MOD)%MOD;
    }
    return (value)%MOD;
}

int main(){
    long long a, b;
    cin>>a>>b;
    cout<<"a raise to the power b is:"<<endl;
    cout<<findpower(a,b)<<endl;
}