//TO CONSTRUCT A TREE GIVEN ITS PREORDER AND POST-ORDER TRAVERSAL

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int n;
        TreeNode* solve(int prestart, int poststart, int preend, vector<int>& preorder, vector<int>& postorder){
            if(prestart>preend){
                return NULL;
            }
            TreeNode* root=new TreeNode(preorder[prestart]);
            if(prestart==preend) return root;
    
            int nextroot=preorder[prestart+1];
    
            int j=poststart;
            while(postorder[j]!=nextroot){
                j++;
            }
            int nums=j-poststart+1;
            root->left=solve(prestart+1, poststart, prestart+nums, preorder, postorder);
            root->right=solve(prestart+1+nums, j+1, preend, preorder, postorder);
            return root;
    
        }
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            n=preorder.size();
            return solve(0, 0, n-1, preorder, postorder);
        }
    };

    int main(){
        
    }