#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank,parent;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }
    }

    int findpar(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]=findpar(parent[node]);
    }

    void unionbyrank(int u,int v){
        int pu=findpar(u);
        int pv=findpar(v);
        if(pu==pv)
        {
            return;
        }
        if(rank[pu]<rank[pv])
        {
            parent[pu]=pv;
        }
        else if(rank[pu]>rank[pv])
        {
            parent[pv]=pu;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;

        }

    }

};

int main()
{
    DisjointSet ds(7);
    
    ds.unionbyrank(1,2);
    ds.unionbyrank(2,3);
    
    ds.unionbyrank(4,5);
    
    ds.unionbyrank(6,7);
    
    ds.unionbyrank(5,6);
    if(ds.findpar(3)==ds.findpar(7))
    {
        cout<<"same"<<endl;
    }
    else{
        cout<<"not same"<<endl;
    }

    ds.unionbyrank(3,7);
    if(ds.findpar(3)==ds.findpar(7))
    {
        cout<<"same"<<endl;
    }
    else{
        cout<<"not same"<<endl;
    }
    return 0;
}