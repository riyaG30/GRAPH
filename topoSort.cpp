//! works on DAG, that is  DIRECTED ACYCLIC GRAPH
//! TOPO SORT - linear ordering of vertices such that if there is an edge 
//! b/w u & v, u appears before V in that ordering

#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int vis[],stack<int> &st,vector<int> adj[])
{
    vis[node] = 1;
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            dfs(it,vis,st,adj);
        }
    }
    st.push(node);
}
vector<int> topoSort(int V, vector<int> adj[])
{
    int vis[V] = {0};
    stack<int> st;
    vector<int> topo;
    for(int i  = 0; i < V; i++)
    {
        if(!vis[i])
        {
            dfs(i,vis,st,adj);
        }
    }
    vector<int> ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
// TC - O(V+E)
//? intuition - 
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

