#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
    public:
    vector<int> tree;
    int n;
    //CONSTRUCTOR
    SegmentTree(const vector<int>& arr){
        n=arr.size();
        tree.resize(4*n);
        buildsegment(0,0, n-1, tree);
    }

    //BUILDING SEGMENT TREE
    //TC=O(4*n)==O(n)
    void buildsegment(int i, int l, int r, vector<int>& arr){
        if(l==r){
            tree[i]=arr[l];
            return;
        }
        int mid=(l+r)/2;
        buildsegment(2*i+1, l, mid, arr);
        buildsegment(2*i+2, mid+1, r, arr);
        tree[i]=tree[2*i+1]+tree[2*i+2];
    }

    //UPDATING VALUE(POINT UPDATE)
    //TO CHANGE VALUE OF ANY INDEX
    //Updates the value of nums[index] to be val.
    void update(int index, int i, int val, int l, int r){
        if(l==r){
            tree[i]=val;
            return;
        }
        int mid=(l+r)/2;
        if(index<=mid){
            update(index, 2*i+1, val, l, mid);
        }
        else{
            update(index, 2*i+2, val, mid+1, r);
        }
        tree[i]=tree[2*i+1]+tree[2*i+2];
    }

    //TO FIND THE SUM OF THE QUERY RANGE 
    //Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
    //O(logn)
    int sumRange(int start, int end, int l, int r, int i){
        if(l>end || r<start) return 0;
        else if(l>=start && r<=end) return tree[i];

        
        int mid=(l+r)/2;
        return sumRange(start, end, l, mid, 2*i+1)+sumRange(start, end, mid+1, r, 2*i+2);
    }

    //LAZY PROPAGATION
    //UPDATING VALUES IN A RANGE
    //LAST WE STUDIED ABOUT JUST UPDATING ONE VALUE OF ANY INDEX
    //THIS METHOD IS USED TO UPDATE THE VALUEIN A RANGE i.e., [l,r]
    
    
};

