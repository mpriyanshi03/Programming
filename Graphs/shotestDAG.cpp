#include <bits/stdc++.h>
using namespace std;
class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdges(int u, int v, int w)
    {
        pair<int, int> p = make_pair(v, w);
        adj[u].push_back(p);
    }

    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &s)
    {
        visited[node] = true;
        for (const auto &neighbour : adj[node])
        {
            if (!visited[neighbour.first])
            {
                dfs(neighbour.first, visited, s);
            }
        }
        s.push(node);
    }

    void shortest(int src, vector<int> &dist, stack<int> &s)
    {
        dist[src] = 0;

        while(!s.empty())
        {
            int top=s.top();
            s.pop();
            if(dist[top]!=INT_MAX)
            {
                for(auto& neighbour : adj[top])
            {
                if((dist[top] + (neighbour.second) )< dist[neighbour.first])
                {
                    dist[neighbour.first]=dist[top] + neighbour.second;
                }
            }
            }

            
        }
    }
};

int main()
{
    int ve, e;
    cin >> ve >> e;
    graph g;

    for (int i = 1; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdges(u, v, w);
    }
    unordered_map<int, bool> visited;
    stack<int> s;

    for (int i = 0; i < ve; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited, s);
        }
    }
    int src = 1;
    vector<int> dist(ve);
    for (int i = 0; i < ve; i++)
    {
        dist[i] = INT_MAX;
    }
    g.shortest(src,dist,s);
    
    for(int i=0;i<dist.size();i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}