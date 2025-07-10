/* 
1. SORT IN INCREASING ORDER OF THEIR WTS
*/

#include <bits/stdc++.h>
using namespace std;

class Krushkal{
    vector<int> parent;
    vector<int> rank;
    
    
    int find(int node){
        if(node==parent[node]) return node;

        return parent[node]=find(parent[node]); 
    }

    //BY RANK
    void Union(int u, int v){
        int ultimate_u=find(u);
        int ultimate_v=find(v);

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
    int krushkal(vector<vector<int>> & vec){
        
        int sum=0;
        
        for(auto& it: vec){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            
            int p1=find(u);
            int p2=find(v);
            
            if(p1!=p2){
                Union(u, v);
                sum+=wt;
            }
            
        }
        return sum;
    }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        parent.resize(V);
        rank.resize(V, 0);
        
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        
        vector<vector<int>> vec;
        
        
        for(auto& it: edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
                
            vec.push_back({u, v, wt});
        }
        auto comparator= [&](vector<int>& vec1,vector<int>& vec2){
            return vec1[2]<vec2[2];
        };
        sort(vec.begin(), vec.end(), comparator);
        
        return krushkal(vec);
        
    }
};