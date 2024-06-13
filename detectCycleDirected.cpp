//! very very important
#include <bits/stdc++.h>
using namespace std;
bool dfsCheck(int node, vector<int> adj[],int vis[], int pathVis[])
{
    vis[node] = 1;
    pathVis[node] = 1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            if(dfsCheck(it,adj,vis,pathVis) == true) return true;
        }
        else if (vis[it] == 1 && pathVis[it] == 1)
        {
            //? means it has been visted and that also in the same path hence cyclic
            return true;
        }
        
    }
    pathVis[node] = 0; // backtracking, it means that wo path me ab consoder nai kar re hai
    
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    int vis[V] = {0};
    int pathVis[V] = {0};
    for(int i = 0; i < V; i++)
    {
        if(!vis[i])
        {
            if(dfsCheck(i,adj,vis,pathVis) ==  true)  return true;
        }
    }
    return false;
}
int main()
{
    int n, m;
    cin>>n>>m;
    int adj[n+1][n+1]; // O(n^2) space
    for(int i = 0; i <m;i++)  // O(n) time to store
    {
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1; // remove this when directed graph

    }
    return 0;
} 