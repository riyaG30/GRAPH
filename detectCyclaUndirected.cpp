#include <bits/stdc++.h>
using namespace std;
//? ------------------------------------BFS WAY------------------------
bool detect(int src, vector<int> adj[], int vis[])
{
    vis[src] = 1;
    queue<pair<int,int>>q;
    q.push({src,-1});
    while(!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto adjacentNode : adj[node])
        {
            if(vis[adjacentNode] != 1 )
            {
                vis[adjacentNode] = 1;
                q.push({adjacentNode,node});
            }
            else if(parent != adjacentNode)
            return true;
        }
    }
   return  true;
}
bool isCycle(int V, vector<int> adj[])
{ // assuming 0 based
    int vis[V] = {0};
    for(int i = 0;  i< V; i++)
    {
        if(!vis[i])
        {
            if(detect(i,adj,vis)) 
            return true;
        }
    }
    return false;
}
//! TC  = O(N+2E)

//?  ----------------------NOW DFS WAY----------------------------------
bool dfs(int node, int parent, vector<int> vis,vector<int> adj[])
{
    vis[node] = 1;
    for(auto adjacentNode : adj[node])
    {
        if(!vis[node])
        {
            // if anywhere in between only tells it has true, then it can directly return answer
           if(dfs(adjacentNode,node,vis,adj) == true) return true; 
        }
        // if visited and is not equal to parent
        else if (parent != adjacentNode) 
        {
            return true;
        }
    }
    return false;
}
 bool isCycle(int V, vector<int> adj[])
 {
    vector<int> vis;
    for(int i  = 0; i < V; i++)
    {
        if(!vis[i])
        {
           if( dfs(i,-1,vis,adj) == true) return true;
        }
    }
    return false;
 }
 //! SC- O(N)
 //! TC - O(N+2E)
int main()
{
    int n,m;
    cin>> n>>m;
    vector<int> adj[n+1];// each element of array has a vector
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        //! or we can say SC-  O(2E)
    }
    return 0;
}