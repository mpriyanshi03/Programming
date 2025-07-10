//USE KAHN'S ALGO TO FIND THE TOPOLOGICAL SORTING IF WE COULDN'T FIND THE TOPO SORTING THAT MEANS THE GRAPH IS CYCLIC

#include <bits/stdc++.h>
using namespace std;

class bfs{
    public:
    bool topologicalSort(vector<vector<int>>& adj) { 
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
          int node=0;
          
          while(!que.empty()){
              int curr=que.front();
              que.pop();
              node++;
              
              for(auto &v : adj[curr]){
                  indegree[v]--;
                  if(indegree[v]==0){
                      que.push(v);
                  }
              }
          }
          if(node < n) return true; //cyclic
          return false;
      }
};