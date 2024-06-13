#include <bits/stdc++.h>
using namespace std;
//! -------------------------------BFS----------------------
bool isBipartite(int V, vector<int> adj[])
{
    queue<int> q;
    q.push(0); // starting from 0
    int colour[V];
    for (int i = 0; i < V; i++)
    {
        colour[i] = -1; // initially all colours are like this
    }
    colour[0] = 0; // first one coloring
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            // if adjacent node is not yect coloures, we wil give opposite color
            if (colour[it] == -1)
            {
                colour[it] = !colour[node];
                q.push(it);
            }
            // adjacent node has same one, means someone else wd have colourd it
            // hence not bipartite
            else if (colour[it] == colour[node])
            {
                return false;
            }
        }
    }
    return true;
    //? TC of BFS only - O(N+2E)
}
//! -------------------------------DFS----------------------
bool dfs(int node, int col, int color[],vector<int>adj[])
{
    color[node] = col;
    for(auto it :adj[node])
    {
        if(color[it] != -1){
            dfs(it,!col,color,adj);
        }
        else if (color[it] == color[node])
        return false;
    }
    return true;
}
bool bipartitr(int V, vector<int> adj[])
{
    int colour[V];
    for (int i = 0; i < V; i++)
    {
        colour[i] = -1; // initially all colours are like this
    }
    colour[0] = 0; // first one coloring
    for(int i = 0; i <V;i++)
    {
        if(colour[i] == -1)
        {
            if(dfs(i,0,colour,adj) == false)
            {
                 return false;
            }
           
        }
    }
    return true;
    //? TC of DSF only - O(N+2E)
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1]; // each element of array has a vector
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        //! or we can say O(2E)
    }
    //? now for weighted graph

    return 0;
}