//TC:O(V+E)

#include <bits/stdc++.h>
using namespace std;

class BFS {
  public:
  //BFS
    bool isCycle(vector<vector<int>>& adj, vector<bool>& vis, int u){
        
        vis[u]=true;
        queue<pair<int, int>> q; //node, parent
        q.push({u,-1});
        
        while(!q.empty()){
            int v=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto& ngbr : adj[v]){
                if(!vis[ngbr]){
                    vis[ngbr]=true;
                    q.push({ngbr, v});
                }
                else{
                    if(ngbr!=parent) return true;
                }
            }
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
                if(isCycle(adj, vis, i))
                    return true;
            }
        }
        return false;
    }
  
};