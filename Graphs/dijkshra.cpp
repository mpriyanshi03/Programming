/*TO FIND SHORTEST PATH BETWEEN SOURCE AND DESTINATION
CANNOT BE APPLIED TO GRAPHS WITH NEGATIVE WT
BECAUSE AS WE WILL CONTINUE THE DISTANCE OR WT WILL DECREASE ONLY AND IT WILL CAUSE INFINITE LOOP
CAN BE IMPLEMENTED USING PRIORITY QUEUE, SET AND QUEUE
T.C= Elog(V)
WE TAKE MIN-HEAP
*/

#include <bits/stdc++.h>
using namespace std;

class Dijkastra
{
public:
  typedef pair<int, int> P;
  vector<int> shortestPath(int n, int m, vector<vector<int>>& edges)
  {

    //CREATING ADJACENCY LIST
    unordered_map<int, vector<pair<int,int>>> adj;
    for(auto& it : edges){
      int u=it[0];
      int v=it[1];
      int time=it[2];
      adj[u].push_back({v, time});
      adj[v].push_back({u, time});
  }
    
    vector<int> distance(n, INT_MAX); //TO FIND THE DISTANCE OF EACH NODE FROM SRC NODE
    distance[0] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;

    pq.push({0, 0}); // wt,node--> STORED IN ASCENDING ODER OF WT
    while (!pq.empty())
    {
      int currwt = pq.top().first;
      int currnode = pq.top().second;
      pq.pop();
      for (auto &vec : adj[currnode])
      {
        int ngbr= vec.first;
        int time= vec.second;


        if (currwt + time < distance[ngbr])
        {
          distance[ngbr] = currwt + time;
          pq.push({distance[ngbr], ngbr});
        }
      }
    }
    for (int &d : distance)
    {
      if (d == INT_MAX)
        d = -1;
    }
    return distance;
  }
};

int main()
{
  Dijkastra dj;
  int n= 6, m= 6;
  vector<vector<int>>edges = {{0, 2, 1}, {0, 1, 3}, {1, 3, 4}, {2, 3, 2}, {3, 4, 2}, {3, 5, 1}};
  vector<int> distance= dj.shortestPath(n, m , edges);

  for(auto &it : distance){
    cout<<it<<" ";
  }
  cout<<endl;
}