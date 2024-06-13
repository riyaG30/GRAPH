#include <bits/stdc++.h>
using namespace std;
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