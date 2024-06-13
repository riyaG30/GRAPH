#include <bits/stdc++.h>
using namespace std;
bool isPossible(int N, vector<pair<int,int>> &pre)
{
    //? create the graph
    vector<int>adj[N];
    for(auto it : pre)
    {
        adj[it.first].push_back(it.second);
    }
    vector<int> indegree(N,0);
    for(int i  =0; i <N; i++)
    {
        for(auto it:adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int>q;
    for(int i = 0; i < N; i++)
    {
        if(indegree[i] == 0) q.push(i);
    }
    vector<int> topo;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node])
        {
             indegree[it]--;
            if(indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    if(topo.size() == N) return true;
    else
    return false;
}
int main()
{
    
    return 0;
}