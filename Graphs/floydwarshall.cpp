/* 
    FINDS THE SHORTEDS DISTANCE BETWEEN EVERY PAIR OF VERTICES IN A GIVEN EDGE WEIGHTEDCTED GRAPH
    Works for both the directed and undirected weighted graph
    Can handle graphs with both positive and negative weight edges.
    It does not work for the graphs with negative cycles(where the sum of the edges in a cycle is negative).
*/

#include <bits/stdc++.h>
using namespace std;

class FloydWarshall{
    public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n=dist.size();
        
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][via] != 1e8 && dist[via][j]!= 1e8)
                        dist[i][j]=min(dist[i][j], dist[i][via]+dist[via][j]);
                }
            }
        }
    }
};