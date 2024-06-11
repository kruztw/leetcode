經過每個節點的最短距離

```cpp=
vector<vector<int>> dp(n, vector<int>(1<<n));
for (int i = 0; i < n; ++i)
    ans = min(ans, dfs(i, 1<<i, adj, dp));

int dfs(int p, int mask, vector<vector<int>> &adj, vector<vector<int>> &dp) {
    if (dp[p][mask] == -1) {
        int n = adj.size();
        int ret = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (mask & (1<<i))
                continue;
                
            ret = min(ret, adj[p][i] + dfs(i, mask|(1<<i), adj, dp))
        }
        dp[p][mask] = ret;
    }
        
    return dp[p][mask];
}
```

[leetcode 943](https://leetcode.com/problems/find-the-shortest-superstring/description/)