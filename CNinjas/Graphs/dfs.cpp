#include <bits/stdc++.h>
using namespace std;
class DFS {
public:
    void dfs(int node, vector<int> &visited, vector<int> &result,  vector<vector<int>>& adj) {
        visited[node] = 1;
        result.push_back(node);
        
        for (int ngbr : adj[node]) {
            if (!visited[ngbr]) {
                dfs(ngbr, visited, result, adj);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<vector<int>>& adj) {
        vector<int> visited(V, 0);
        vector<int> result;
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, result, adj);
            }
        }
        
        return result;
    }
};