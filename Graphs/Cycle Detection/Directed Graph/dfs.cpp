#include <bits/stdc++.h>
using namespace std;

class DFS {
  public:
    bool Cycle(vector<vector<int>>& adj, vector<bool>& vis, 
    vector<bool>& inRec, int u){
        vis[u]=true;
        inRec[u]=true;
        
        for(auto& v: adj[u]){
            
            if(!vis[v] && Cycle(adj, vis, inRec, v)) return true;  
        
            else if(inRec[v]==true) return true;
        }
        inRec[u]=false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto& it: edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        vector<bool> visited(V, false);
        vector<bool> inRecur(V, false);
        for(int i=0;i<V;i++){
            if(!visited[i] && Cycle(adj, visited, inRecur, i))
                return true;
        }
        return false;
        
    }
};