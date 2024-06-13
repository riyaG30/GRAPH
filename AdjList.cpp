#include <bits/stdc++.h>
using namespace std;
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
        // in this way at every index we r storing the neighbour list
        // it will take space O(2m)  because for every edge there is 2 node
        //! or we can say O(2E)

    }
    //? now for weighted graph 
    // we will store the pairs in vector , one will have node and other weight
    return 0;
}