/* 
USED TO FIND THE MINIMUM SPNNING TREE 
*/
#include <bits/stdc++.h>
using namespace std;

class Prims{
    public:
    typedef pair<int, int> P;
    int spanningTree(int n, vector<vector<int>> adj[]) {
        // code here
        
        priority_queue<P, vector<P>, greater<P>> pq; //wt, node
        pq.push({0, 0});
        vector<bool> isMST(n, false);
        int sum=0;
        
        while(!pq.empty()){
            auto curr=pq.top();
            int wt=curr.first;
            int node=curr.second;
            pq.pop();
            if(isMST[node]==true)
                continue;
            
            isMST[node]=true;
            sum+=wt;
            for(auto& it: adj[node]){
                int ngbr=it[0];
                int ngbrwt=it[1];
                if(!isMST[ngbr]){
                    pq.push({ngbrwt, ngbr});
                }
            }
        }
        return sum;
    }
};