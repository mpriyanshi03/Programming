/*
The Boyer-Moore voting algorithm used to find the majority element among the given elements that have more than N/ 2 occurrences. 
This takes 2 traversals over the given elements, 
T.C O(N)  
S.C O(1) 
*/

#include <bits/stdc++.h>
using namespace std;

class Boyer{
    public:
    int majority(vector<int>& nums){
        int n=nums.size();
        int candidate=-1;
        int cnt=0;

        //ASSUME
        for(int i=0;i<n;i++){
            if(cnt==0){
                candidate=nums[i];
            }
            else{
                if(nums[i]==candidate){
                    cnt++;
                }
                else{
                    cnt--;
                }
            }
        }

        //CHECKING IF OUR ASSUMTION IS CORRECT
        int total=0;
        for(int i=0; i<n;i++){
            if(nums[i]==candidate){
                total++;
            }
        }
        if(total>n/2) return candidate;
        else return -1;
    }

};

int main(){
    Boyer bm;

    vector<int> nums={1,2,2,4,5,7,2};
    cout<< bm.majority(nums)<<endl;

}