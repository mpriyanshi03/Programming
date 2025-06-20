//DISJOINT SET =(O(4* alpha)) IS USED TO TELL IF A VERTEX BELONG TO THE SAME COMPONENT OR NOT IN CONSTANT TIME
//USUALLY USED IN DYNAMIC GRAPHS
//find parent() and union()
//union() by rank and size
//union()- IT IS TO JOIN THE COMPONENTS I.E., THE EDGES
//union() T.C = O(4* alpha)= O(constant) since alpha is too small

#include <bits/stdc++.h>
using namespace std;

class Disjoint{
    vector<int> rank, parent;
    public:
    Disjoint(int n){
        rank.resize(n+1, 0); //n+1 for 1 based indexing in graph so it works for both 0 and 1 based indexing
        parent.resize(n+1);

        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUltimateParent(int node){
        if(node==parent[node]) return node;

        return parent[node]=findUltimateParent(parent[node]); 
    }

    //BY RANK
    void unionByRank(int u, int v){
        int ultimate_u=findUltimateParent(u);
        int ultimate_v=findUltimateParent(v);

        if(ultimate_u==ultimate_v) return;

        else if(rank[ultimate_u]<rank[ultimate_v]){
            parent[ultimate_u]=ultimate_v;
        }
        else if(rank[ultimate_v]<rank[ultimate_u]){
            parent[ultimate_v]=ultimate_u;
        }
        else{
            parent[ultimate_v]=ultimate_u;
            rank[ultimate_u]++;
        }

    }
};

int main(){
    Disjoint ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    //if 3 and 7 belong to same component or not
    if(ds.findUltimateParent(3)== ds.findUltimateParent(7))
    {
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not same"<<endl;
    }

    ds.unionByRank(3,7);
    //if 3 and 7 belong to same component or not
    if(ds.findUltimateParent(3)== ds.findUltimateParent(7)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not same"<<endl;
    }
    

}
