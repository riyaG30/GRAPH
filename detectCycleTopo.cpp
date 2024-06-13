#include <bits/stdc++.h>
using namespace std;
//! if topo sort comes out to be exactly V elements , then it means it is ACYCLIC
//! if less than V, means there is a CYCLE
bool khans(int V, vector<int>adj[])
{
    vector<int>indegree(V,0);
    for(int i = 0; i <V; i++)
    {
        for(auto it: adj[i])
        indegree[it]++;
    }
    queue<int>q;
    for(int i = 0; i <V; i++)
    {
        if(indegree[i] ==0)
        {
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        // node is in my topo sort now
        // so we will remove it from indegree
        for(auto it :adj[node])
        {
            indegree[it]--;
            if(indegree[it] == 0)
            q.push(it);
        }
    }

//*******----*-*-*-
if (ans.size() == V) return false; // means acyclic
else
return true; //CYCLIC
//! O(V+E) 
}
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
