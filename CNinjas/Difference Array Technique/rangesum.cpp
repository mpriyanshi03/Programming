//YOU ARE GIVEN A NUMS ARRAY AND MANY QUEREIES IN THE FORM (L, R, X)NYOU HAVE TO RETURN THE VALUE AFTER PERFORMING ALL THE QUERIES OON NUMS
// FOR THIS WE USE DIFFERENCE ARRAY

#include<bits/stdc++.h>
using namespace std;

vector<int> range(vector<int>& nums, vector<vector<int>>& queries){
    int n=nums.size();
    vector<int> ans(n);
    for(auto &it : queries){
        int l=it[0];
        int r=it[1];
        int x=it[2];
        nums[l]+=x;
        if(r+1<n){
            nums[r+1]-=x;
        }
    }
    ans[0]=nums[0];
    for(int i=1;i<n;i++){
        ans[i]=ans[i-1]+nums[i];
    }
    return ans;
    
}

int main(){
    int n;
    cout<<"Size of array"<<endl;
    cin>> n;
    vector<int> nums(n,0);
    vector<vector<int>> query={{1,3,2}, {2,4,3}, {0, 2, -2}};
    vector<int> updated=range(nums, query);
    for(auto it : updated){
        cout<< it <<" ";
    }
    cout<<endl;
}