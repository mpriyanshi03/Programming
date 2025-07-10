/* 
NOT ALL GRAPHS HAVE EULERIAN PATH
BE CAREFUL FROM WHICH NODE YOU START YOUR EULERIAN PATH(EP)
EULERIAN PATH: WHICH STARTS AND ENDS ON THE SAME NODE
ALL VERTICES WITH NON ZERO DEGREE MUST  BELONG TO A SINGLE CONNECTED COMPONENT.
ALL VERTICES HAVE EVEN DEGREES: EULERIAN CIRCUIT(EC)
SEMI-ELUERIAN GRAPH: JAB EP HAI PAR EC NHI--->STARTING AND ENGING NODE KA DEGREE ODD HOGA
ODD DEGREE==2--> EP
ODD DEGREE>2--> NONE
ODD DEGREE==0--> EC
*/
/* 
IN DIRECTED GRAPHS FIND THE INDEGREE AND OUTDEGREE OF THE EACH NODE
FIND 2 NODES SUCH THAT:
SOURCE:  OUTDEGREE[NODE]-INDEGREE[NODE]=1;
DEST:    INDEGREE[NODE]-OUTDEGREE[NODE]=1;
OTHER NODE: INDEGREE[NODE]==OUTDEGREE[NODE]

IF IT'S A EUCLERIAN CIRCUIT THEN INDEGREE[NODE]==OUTDEGREE[NODE] OF EACH NODE
STARING POINT=OUTDEGREE[NODE]-INDEGREE[NODE]=1
*/

#include <bits/stdc++.h>
using namespace std;

class EulerCircuit {
  public:
    void dfs(int u,vector<bool>&visited, vector<int> adj[]){
        visited[u]=true;
        
        for(auto&v : adj[u]){
            if(!visited[v]){
            dfs(v, visited, adj);
        }
        }
    
    }
    bool isConnected(int V, vector<int> adj[]){
        int nonzerodeg=-1;
        for(int i=0;i<V;i++){
            if(adj[i].size()!=0){
                nonzerodeg=i;
                break;
            }
        }
        vector<bool>visited(V, false);
        dfs(nonzerodeg, visited, adj);
        
        for(int i=0;i<V;i++){
            if(!visited[i] && adj[i].size()>0){
                return false;
            }
        }
        return true;
    }
    int isEulerCircuit(int V, vector<int> adj[]) {
        // Code here
        
        if(!isConnected(V, adj)) return 0;
        
        int odd=0;
        
        for(int i=0;i<V;i++){
            if(adj[i].size()%2!=0){
                odd++;
            }
        }
        if(odd>2) return 0;
        if(odd==2) return 1;
        return 2;
    }
};


