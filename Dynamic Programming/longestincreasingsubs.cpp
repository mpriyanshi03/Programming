#include<bits/stdc++.h>
#include <iomanip>  // Required for std::oct
using namespace std;


vector<int> lengthOfLIS(vector<int>& nums){
    int n=nums.size();

    vector<int> dp(n,1);
    int maxlen=1, ind=0;
    vector<int> prev(n,-1);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(nums[i]>nums[j]){
                if(dp[j]+1> dp[i]){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                    if(maxlen<dp[i]){
                        maxlen=dp[i];
                        ind=i;
                    }
                }
            }
        }
    }
    vector<int> ans;
    while(ind!=-1){
        ans.push_back(nums[ind]);
        ind=prev[ind];
    }
    reverse(ans.begin(), ans.end());
    return ans;
    
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    vector<int> longestsub=lengthOfLIS(nums);
    for (auto& it: longestsub){
        cout<<it<<" ";
    }
    cout<<endl;


}