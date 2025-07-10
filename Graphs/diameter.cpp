/* 
DIAMETER OF UNDIRECTED GRAPH
*/

#include <bits/stdc++.h>
using namespace std;

class diameter{
    public:
    pair<int, int> bfs(unordered_map<int, vector<int>> &adj, int u){
        queue<int> q;
        q.push(u);
        int farthest=u;

        unordered_map<int, bool> visited;
        visited[u]=true;
        int level=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                int curr=q.front();
                q.pop();
                farthest=curr;
                for(auto&ngbr : adj[curr]){
                    if(!visited[ngbr]){
                        visited[ngbr]=true;
                        q.push(ngbr);
                    }
                }

            }
            if(!q.empty())
                level++;
        }
        return {farthest, level};

    }


    int find(unordered_map<int, vector<int>> &adj){
        //starting bfs from 0;
        auto [farthestNode, dist]=bfs(adj, 0); 

        auto [otherNode, diameter]=bfs(adj, farthestNode);
        return diameter;
    }

    
    int diameteroftree(vector<vector<int>>& edges){
        int n=edges.size();
        
        unordered_map<int, vector<int>> adj;
        for(auto&it: edges){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return find(adj);
    }
};