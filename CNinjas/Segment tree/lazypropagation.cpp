#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
    public:
    vector<int> tree, lazy;
    int n;
    //CONSTRUCTOR
    SegmentTree(const vector<int>& arr){
        n=arr.size();
        tree.resize(4*n);
        lazy.resize(4*n,0);
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

    //LAZY PROPAGATION
    //UPDATING VALUES IN A RANGE
    //LAST WE STUDIED ABOUT JUST UPDATING ONE VALUE OF ANY INDEX
    //THIS METHOD IS USED TO UPDATE THE VALUEIN A RANGE i.e., [l,r]
    //T.C : O(logn)
    //S.C : O(n)
    void update(int i, int l, int r, int s, int e, vector<int>& arr, int val){
        if(lazy[i]!=0){
            tree[i]+=(r-l+1)*val;
            if(l!=r){ 
                lazy[2*i+1]+=lazy[i];
                lazy[2*i+2]+=lazy[i];
            }
            lazy[i]=0;

        }

        if(r<s || l>e) return;

        if(l>=s && r<=e){
            tree[i]+=(r-l+1)*val;
            if(l!=r){
                lazy[2*i+1]+=val;
                lazy[2*i+2]+=val;
            }
            return;
        }
        int mid=(l+r)/2;
        update(2*i+1, l, mid, s, e, arr, val);
        update(2*i+2, mid+1, r, s, e, arr, val);

        tree[i]=tree[2*i+1]+tree[2*i+2];

    }
};