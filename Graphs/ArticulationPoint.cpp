/*  lowest[v]>= discovery[u]
    v=child
    u=parent
    then u will be articulation point
 */

#include <bits/stdc++.h>
using namespace std;

class ArticulationPoint {
  public:
    int timer=1;
    void dfs(int u, int parent, vector<bool> &visit, vector<int>& lowest,
        vector<int> &discover, vector<vector<int>> &adj, vector<bool> &isAP){
            int cnt=0;
            visit[u]=true;
            discover[u]=lowest[u]=timer;
            timer++;
            
            for(auto& v: adj[u]){
                if(v==parent) continue;
                
                if(!visit[v]){
                    dfs(v, u, visit, lowest, discover, adj, isAP);
                    
                    lowest[u]=min(lowest[u], lowest[v]);
                    if(parent!=-1 && lowest[v]>=discover[u]){
                        isAP[u]=true;
                    }
                    cnt++;
                }
                else{
                    lowest[u]=min(lowest[u], discover[v]);
                }
                
            }
            //for root
            if(parent==-1 && cnt>1){
                isAP[u] = true;
            }
        }
        
    vector<int> articulationPoints(int n, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(n);
        for(auto& it: edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> discover(n, 0);
        vector<int> lowest(n, 0);
        int parent=-1;
        vector<bool> visit(n, false) , isAP(n, false);
        vector<int> point;
        
        for(int i=0;i<n;i++){
            if(!visit[i]){
                dfs(i, parent, visit, lowest, discover, adj, isAP);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (isAP[i]) point.push_back(i);
        }
        return point.empty() ? vector<int>{-1} : point;
        
    }
};