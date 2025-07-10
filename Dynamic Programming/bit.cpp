#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums={2,1,4};
    int n=nums.size();
    vector<int> ans(n,1);
    for(int i=0;i<n;i++){
        if(nums[i] & 1)//odd
        {
            ans[i]=-1;
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    

}