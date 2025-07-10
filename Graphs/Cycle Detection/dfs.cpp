// agar parent hai to continue  kr jaayege otherwise agar wo visited hai or uss node ka parent nhi hai this implies
//ki cycle hai
//TC:O(V+E)

#include <bits/stdc++.h>
using namespace std;
class dfs {
public:
    bool isCycle(vector<vector<int>>& adj, vector<bool>& vis, 
    int parent, int u){
        vis[u]=true;
        
        for(auto& v: adj[u]){
            if(v==parent) continue;
            if(vis[v]) return true;  
            
            if(isCycle(adj, vis, u, v)) return true;
        }
            
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto& it: edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> vis(V, false);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isCycle(adj, vis, -1, i))
                    return true;
            }
        }
        return false;
    }

};