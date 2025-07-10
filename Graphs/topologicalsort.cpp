// Function to return list containing vertices in Topological order.
// KAHN'S ALGO- TOPOLOGICAL SORT USING BFS
//FOR DIRECED ACYCLIC GRAPH

#include <bits/stdc++.h>
using namespace std;
class DFS{ 
  public:
    void dfs(vector<vector<int>>& adj, int u, stack<int> &s,vector<bool>& visited){
        visited[u]=true;
        
        //pehle mere(u) ke baccho ko daalo stack mein
        for(auto& v: adj[u]){
            if(!visited[v]){
                dfs(adj, v, s, visited);
            }
        }
        //ab mujhe daalo stack mein
            s.push(u);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<int> ans;
        vector<bool> visited(V, false);
        for(auto& it: edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        
        stack<int> s;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(adj, i, s, visited);
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};


class BFS {
    public:
      vector<int> topologicalSort(vector<vector<int>>& adj) { 
          int n=adj.size();
          
          vector<int> indegree(n, 0);
          
          for(int u=0;u<n;u++){
              for(auto& v : adj[u]){
                  indegree[v]++;
              }
          }
          queue<int> que;
          for(int u=0;u<n; u++){
              if(indegree[u]==0){
                  que.push(u);
              }
          }
          vector<int> result;
          while(!que.empty()){
              int curr=que.front();
              result.push_back(curr);
              que.pop();
              
              for(auto &v : adj[curr]){
                  indegree[v]--;
                  if(indegree[v]==0){
                      que.push(v);
                  }
              }
          }
          return result;
      }
  };

  