#include <bits/stdc++.h>
using namespace std;

class DSUBySize{
    vector<int> parent, size;
    public:
    DSUBySize(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findPar(int node){
        if(parent[node]==node) return node;
        return parent[node]=findPar(parent[node]);
    }

    void Union(int u, int v){
        int ult_u=findPar(u);
        int ult_v=findPar(v);

        if(ult_u==ult_v){
            return;
        }
        if(size[ult_u]<size[ult_v]){
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }
        else if(size[ult_u]>size[ult_v]){
            parent[ult_v]=ult_u;
            size[ult_u]+=size[ult_v];
        }
        else if(size[ult_u]==size[ult_v]){
            parent[ult_v]=ult_u;
            size[ult_u]+=size[ult_v];
        }
    }

};
