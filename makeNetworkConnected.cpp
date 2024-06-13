#include <bits/stdc++.h>
using namespace std;
int solve(int n , vector<vector<int>> &edges)
{
    DisjointSet ds(n);
    int cntExtra = 0;
    for(auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        if(ds.findUlt(u) ==  ds.findUlt(v))
        {
            cntExtra++;
        }
        else{
            ds.unionByRank(u,v);
        }
    }
    // DS done
    int cntC = 0;
    for(int i = 0; i < n; i++)
    {
        if(ds.parent[i] == i) cntC++;
    }
    int ans = cntC-1;
    if(cntExtra >= cntC)
    {
        return ans;
    }
    
    return -1;
}
int main()
{

    return 0;
}