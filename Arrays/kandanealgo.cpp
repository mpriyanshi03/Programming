#include <iostream>
#include <vector>
using namespace std;
//TO FIND MIN SUM
int kandanemin(vector<int> &nums, int n){
    int currminsum=nums[0], minsum=nums[0];

        for(int i=1;i<n;i++){
            currminsum=min(currminsum+nums[i], nums[i]);
            minsum=min(minsum, currminsum);
        }
        return minsum;
}
//TO FIND THE MAX SUM
int kandanemax(vector<int> &nums, int n){
    int currmaxsum=nums[0], maxsum=nums[0];

        for(int i=1;i<n;i++){
            currmaxsum=max(currmaxsum+nums[i], nums[i]);
            maxsum=max(maxsum, currmaxsum);
        }
        return maxsum;
}

int main(){
    int n;
    cout<<"what's the size of the vector"<<endl;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    cout<<kandanemax(vec, n)<<endl<<kandanemin(vec, n);
}