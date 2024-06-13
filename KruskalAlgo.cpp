//! used to find minimum spanning tree
#include <bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> rank, parent;
    public :
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i = 0; i <= n; i++) // for one base indexing
        {
            parent[i] = i;
        }
    }
        int findUlt(int node)  //? finding ultimate parent
        {
            if(node == parent[node])

            {
                return node;
            }
            //! path compression
            return parent[node] =  findUlt(parent[node]);

        }
        void unionByRank(int u , int v)
        {
            int ulp_u = findUlt(u);
            int ulp_v = findUlt(v);
            if(ulp_u == ulp_v)
            {
                return ;
            }
            if(rank[ulp_u] < rank[ulp_v])
            {
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_u] > rank[ulp_v])
            {
                parent[ulp_v] = ulp_u;
            }
            else{
                  parent[ulp_v] = ulp_u;
                  rank[ulp_u]++;
            }
        }
    
};
int spanningTree (int v, vector<vector<int>> adj[])
{
    vector<pair<int,pair<int, int>>> edges;
    for(int i = 0; i <V; i++)
    {
        for(auto it : adj[i])
        {
            int adjNode = it[0];
            int wt = it[1];
            int node = i;
            edges.push_back({wt,{node,adjNode}});
        }
    }
    DisjointSet ds;
    sort(edges.begin(),edges.end());
    int mstWt = 0;
    for(auto it : edges)
    {
        int wt = it.first;
        int v = it.second.second;
        int u = it.second.first;
        if(ds.findUlt(u) != ds.findUlt(v))
        {
            mstWt += wt;
            ds.unionByRank(u,v);
        }
    }
}
int main()
{

    return 0;
}