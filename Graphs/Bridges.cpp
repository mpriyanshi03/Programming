/* 
An edge in an undirected connected graph is a bridge if removing it disconnects the graph. For a disconnected undirected graph, the definition is similar, a bridge is an edge removal that increases the number of disconnected components. 
*/

#include <bits/stdc++.h>
using namespace std;

class Bridges {
public:
    int timer=1;
    void dfs(int u, vector<bool> &visited, int parent, vector<int> &start,
    vector<int>& lowest, vector<vector<int>>& adj, vector<vector<int>>& bridge){
        visited[u]=true;
        start[u]=lowest[u]=timer;
        timer++;

        for(auto& v:adj[u]){
            if(v==parent) continue;

            if(!visited[v]){
                dfs(v, visited, u, start, lowest, adj, bridge);

                lowest[u]=min(lowest[u], lowest[v]);
                if(start[u]<lowest[v]){
                    bridge.push_back({u,v});
                }
            }
            else{
                lowest[u]=min(lowest[u], start[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto & it: connections){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>> bridge;
        vector<int> start(n,-1);
        vector<int> lowest(n,-1);
        vector<bool> visited(n,false);
        int parent=-1;
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i, visited, parent, start, lowest, adj, bridge);
            }
        }
        return bridge;
        
    }
};