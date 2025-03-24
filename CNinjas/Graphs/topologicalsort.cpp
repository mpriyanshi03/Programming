// Function to return list containing vertices in Topological order.
// KAHN'S ALGO- TOPOLOGICAL SORT USING BFS

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      vector<int> topologicalSort(vector<vector<int>>& adj) {
          // Your code here
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

  