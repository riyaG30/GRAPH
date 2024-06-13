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
string findOrder(string dict[], int n,int k )
{
    vector<int> adj[k];
    for(int i = 0; i <n-1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i+1];
        int len = min(s1.size(),s2.size());
        for(int j = 0; j < len; j++ )
        {
            if(s1[j] != s2[j])
            {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
            }
        }
    }
    vector<int> topo = topoSort(k,adj);
    string ans = "";
    for(auto it:topo)
    {
        ans += it;
    }
return ans;
}
int main()
{

    return 0;
}