class DisjointSet
{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
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
    }
};
class Solution
{
public:
    bool isValid(int newr, int newc, int n)
    {
        return (newr >= 0 && newr < n && newc >= 0 && newc < n);
    }
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        DisjointSet ds(n * n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (grid[i][j] == 0)
                    continue;

                for (int ind = 0; ind < 4; ind++)
                {
                    int newr = i + dr[ind];
                    int newc = j + dc[ind];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1)
                    {
                        int node = i * n + j;
                        int adjNodeNo = newr * n + newc;
                        ds.unionBySize(node, adjNodeNo);
                    }
                }
            }
        }
        // till now made all the components
        /// step 2 - > converting every 0 to 1 and checking where i can get maximum
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    continue;
                set<int> components;
                if (grid[i][j] == 0)
                {

                    for (int ind = 0; ind < 4; ind++)
                    {
                        int newr = i + dr[ind];
                        int newc = j + dc[ind];
                        if (isValid(newr, newc, n))
                        {
                            if (grid[newr][newc] == 1)
                            {
                                components.insert(ds.findUPar(newr * n + newc));
                            }
                        }
                    }
                    // now travelled in all 4 directions
                }
                int size = 0;
                for (auto it : components)
                {
                    size += ds.size[it];
                }
                ans = max(ans, size + 1);
            }
        }
        for (int i = 0; i < n * n; i++)
        {
            ans = max(ans, ds.size[ds.findUPar(i)]);
        }
        return ans;
    }
};