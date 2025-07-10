#include <bits/stdc++.h>
using namespace std;

int main(){
    int nums1[2] = {1,2};
    int nums2[2] = {3,4};
    int ans1=0, ans2=0;
    for(int i=0;i<2;i++){
        ans1^=nums1[i];
    }
    for(int i=0;i<2;i++){
        ans2^=nums2[i];
    }

    cout<<ans1<<endl<<ans2<<endl;

    int nums3[3] = {2,1,3};
    int nums4[4] = {10,2,5,0};
    int ans3=0, ans4=0;
    for(int i=0;i<3;i++){
        ans3^=nums3[i];
    }
    for(int i=0;i<4;i++){
        ans4^=nums4[i];
    }
    cout<<ans3<<endl<<ans4<<endl;

}