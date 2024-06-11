```cpp=
int maximumInvitations(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<unordered_map<int,int>> adj(m+n+1);
        
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (grid[i][j])
                adj[i][m+j] = 1;
    for (int i = 0; i < n; ++i)
        adj[m+i][m+n] = 1;
        
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        vector<bool> visit(m+n+1);
        ans += match(adj, i, visit);
    }
    return ans;
}

bool match(vector<unordered_map<int,int>> &adj, int i, vector<bool> &visit) {
    if (i == adj.size() - 1)
        return true;

    for (auto [j, c]: adj[i])
        if (c && !visit[j]) {
            visit[j] = true;
            swap(adj[i][j], adj[j][i]);
            if (match(adj, j, visit))
                return true;
            swap(adj[i][j], adj[j][i]); // true 的話不會變回來
        }
    return false;
}
```