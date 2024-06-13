#include <bits/stdc++.h>
using namespace std;
// edges data is like , the index is given like, (U,V, WT)
void topoSort (int node, vector<pair<int,int>> adj[],
vector<int> vis, stack<int> &st)
{
    vis[node] = 1;
    for(auto it: adj[node])
    {
        if(!vis[it.first])
        {
            topoSort(it.first,adj,vis,st);
        }
    }
    st.push(node);
}
vector<int> shortestPAth(int n, int  m, vector<int> edges[])
{
    //? creating the graph
    vector<pair<int,int>> adj[n];
    for(int i = 0; i <m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v,wt});
    }
    // finding the toppo sort
    stack<int> st;
    vector<int> vis(n);
    for(int i = 0; i <n; i++)
    {
        if(vis[i] == 0)
        {
            topoSort(i,adj,vis,st);
        }
    }

    //! step 2: dp the distance thing
    vector<int> dist(n);
    for(int i = 0; i <n; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[0] = 0; //? considering that source node is 0 here
    while(!st.empty())
    {
        int node = st.top();
        st.pop();
        for(auto it : adj[node])
        {
            int v = it.first;
            int wt = it.second;
            if(dist[node] + wt < dist[v])
            {
                dist[v] = dist[node] + wt;
            }
        }
    }
    return dist;

}
//! TC - O(V+E)(dfs) +  O(n+m)
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
     }
    //? now for weighted graph 
    // we will store the pairs in vector , one will have node and other weight
    return 0;
}