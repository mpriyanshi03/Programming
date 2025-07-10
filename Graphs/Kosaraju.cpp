/* 
APPROACH TO FIND STRONGLY CONNECTED COMPONENTS(SSC)
SSC-> In a directed graph, A SUBSET OF VERTICES WHERE EACH VERTEX IN A SUBSET CAN BE REACHED FROM EVERY OTHER VERTEX OF THE SUBSET
S
1. STORE THE TOPOLOGICAL SORT IN A STACK
2. REVERSE THE DIRECTION OF THE ARROWS(REVERSED GRAPH)
3. USING THE STACK ORDER, CALL DFS
TC: O(V+E)
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    void dfs(int u, vector<bool> &visited, vector<vector<int>> &adj, stack<int>& st){
        visited[u]=true;
        
        for(auto & v: adj[u]){
            if(!visited[v]){
                dfs(v, visited, adj, st);
            }
        }
        st.push(u);
        
    }
    
    void dfsnew(int u, vector<bool> &visited, vector<vector<int>> &adj){
        visited[u]=true;
        
        for(auto&v:adj[u]){
            if(!visited[v]){
                dfsnew(v, visited, adj);
            }
        }
        
    }
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        stack<int> st;
        int n=adj.size();
        vector<bool> visited(n, false);
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i, visited, adj, st);
            }
        }
        
        vector<vector<int>> newadj(n);
        for(int i=0;i<n;i++){
            for(auto& v : adj[i]){
                newadj[v].push_back(i);
            }
        }
        int cnt=0;
        visited=vector<bool> (n, false);
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!visited[node]){
                dfsnew(node, visited, newadj);
                cnt++;
            }
            
        }
        return cnt;
    }
};

