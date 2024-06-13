#include <bits/stdc++.h>
using namespace std;
vector<int> bfs(int V, vector<int>adj[]) // V is no. of nodes
{
    //! assuming it is a 0 based graph, so vis arry of size 0
    int vis[V] = {0};
    vis[0] = 1;
    queue<int>q;
    q.push(0);
    vector<int> ans;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return ans; 
    //! SC - O(n)
    //! TC - O(N) {node} + O(2E){ for each node, it is going to all degrees}
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