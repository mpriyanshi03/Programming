/* 
IN DIKJSTRA NEGATIVE WEIGHTS CANNOT BE USED and CAN'T DETECT NEGATIVE CYCLE
WORKS ONLY ON DIRECTED GRAPH
In the presence of negative weight cycle (whose sum of edge weights is negative) in the graph, the shortest path doesn't exist because with each traversal of the cycle shortest path keeps decreasing.
(V-1)th RELAXATION ARE DONE
If one additional relaxation (Vth) for any edge is possible, it indicates that some edges with overall negative weight has been traversed once more. This indicates the presence of a negative weight cycle in the graph.
*/

#include <bits/stdc++.h>
using namespace std;

class bellmanford{
    public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V,1e8);
        
        dist[src]=0;
        
        for(int i=0;i<V;i++){
            
            for(auto & it: edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
                    if(i==V-1) return{-1}; //NEGATIVE CYCLE CHECKING
                    dist[v]=dist[u]+wt;
                }
            }
        }
        return dist;
        
    }

};