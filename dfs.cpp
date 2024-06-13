#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> adj[],int vis[], vector<int> ans)
{
    vis[node] = 1;
    ans.push_back(node);
    // traverse all its neighbours
    for(auto it : adj[node])
    {
        if(!vis[it])
        {
            dfs(it,adj,vis,ans);
        }
    }
}
vector<int> dfsTraverse(int V, vector<int> adj[])
{
    //asuming here 0 based indexing
    int vis[V] = {0};
    int start = 0;
    vis[start ] = 1;
    vector<int> ans;
    dfs(start,adj,vis,ans);
    return ans;
    //! SC - O(N)
    //! TC - O(N) + O(2E)

}
int main()
{
    int n,m;
    cin>> n>>m;
    vector<int> adj[n+1];// creating the graph
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
       
    }
    return 0;
}