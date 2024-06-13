#include <bits/stdc++.h>
using namespace std;
DisjointSet(int n)
{
public:
    vector<int> rank, parent, size;
    rank.resize(n + 1, 0); // as 1 based indexing
    parent.resize(n + 1);
    size.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
}

int findUPar(int node)
{
    if (node == parent[node])
        return node;
    return parent[node] = findUPar(parent[node]);
    // for path compression
}

void unionByRank(int u, int v)
{
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if (ulp_u == ulp_v)
        return;
    if (rank[ulp_u] < rank[ulp_v])
    {
        parent[ulp_u] = ulp_v;
    }
    else if (rank[ulp_v] < rank[ulp_u])
    {
        parent[ulp_v] = ulp_u;
    }
    else
    {
        parent[ulp_v] = ulp_u;
        rank[ulp_u]++;
    }
}

void unionBySize(int u, int v)
{
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if (ulp_u == ulp_v)
        return;
    if (size[ulp_u] < size[ulp_v])
    {
        parent[ulp_u] = ulp_v;
        size[ulp_v] += size[ulp_u];
    }
    else
    {
        parent[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v];
    }
};

int numProvinces(vecyor<int> adj[], int v)
{
    DisjointSet ds(v);
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (adj[i][j] == 1)
            {
                ds.unionByRank(u, v);
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < v; i++)
    {
        if (ds.findUPar(i) == i)
            cnt++;
    }
    return cnt;
}
int main()
{
    //? adjacency matrix which will be given in question
    int n, m;
    cin >> n >> m;
    vector<int> adj[(n + 1)]; // each element of array has a vector
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push _back(v);
        adj[v].push_back(u);

        cout << numProvinces(adj, n);
    }
    return 0;
}