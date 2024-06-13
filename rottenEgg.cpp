#include <bits/stdc++.h>
using namespace std;

int orangeRotten(vector<vector<int>> & grid)
{
    int n  =grid.size();
    int m = grid[0].size();
    // now first storing all the rotten oranges
    queue<pair<pair<int,int>,int>> q; // {{r,c},t}
    vector<vector<int>> vis;
    for(int i  =0; i < n; i++)
    {
        for(int j = 0; j <m;j++)
        { // first marking all rotten oranges
            if(grid[i][j] == 2)
            {
                q.push({{i,j},0});
                vis[i][j] = 2;
            }
            else{
                vis[i][j] = 0;
            }
        }
    }
    int tm = 0;
    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};
     while(!q.empty())
     {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm,t);
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nrow = r+drow[i];
            int ncol =  c+dcol[i];
            if(nrow>= 0 && nrow <n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
            {
                q.push({{nrow,ncol},t+1});
                vis[nrow][ncol] = 2;
            }
        }
     }
     for(int i = 0; i <n; i++)
     {
        for(int j =0 ; j < m; j++)
        {
            if(vis[i][j] != 2 && grid[i][j] == 1)
            return  -1;
        }
     }
     return tm;
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