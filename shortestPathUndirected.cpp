#include <bits/stdc++.h>
using namespace std;
//! it is given as {u,v}
vector<int> shortestPath(vector<vector<int>>edges, int n, int m,int src)
{
    // creating the graph
    vector<int> adj[n];
    for(auto it :edges)
    {
        // undirected, so both sided graphs
        adj[it[0]].push_back(it[1]);
        adj[it[0]].push_back(it[1]);
    }
    int dist[n];
    for(int i = 0; i < n; i++)
    {
        dist[i] = 1e9;
    }
    
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it :adj[node])
        {
            if(dist[node]+1 < dist[it])
            {
                dist[it] = dist[node]+1;
                q.push(it);
            }
        }

    }
    vector<int> ans(n,-1);
    for(int i = 0; i <m; i++)
    {
        if(dist[i] != 1e9)
        {
            ans[i] = dist[i];
        }
        
    }
    return ans;
}
//! we using queue, because it is already in sorted DS here
int main()
{
    int n,m;
    cin>> n>>m;
    vector<int> adj[(n+1)];// each element of array has a vector
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        // in this way at every index we r storing the neighbour list
        // it will take space O(2m)  because for every edge there is 2 node
        //! or we can say O(2E)

    }
    //? now for weighted graph 
    // we will store the pairs in vector , one will have node and other weight
    return 0;
}