from[0][v]: 以 v 為 root 的 MIS
dp[0][e]: 假設 e = (p -> v), 方向 p 到 v 看過去的 MIS
miss[v]: v 的 parent, n 代表已經完成

0: 不包含
1: 包含

```cpp=
void dfs(int e) {
  if (dp[0][e] >= 0 || dp[1][e] >= 0) return;

  int p = edges[e].first, v = edges[e].second;
  dp[0][e] = 0, dp[1][e] = 1;
  if (miss[v] < 0) {
    for (int u : adj[v]) {
      if (u == p) continue;
      int ne = mp[{v, u}];
      dfs(ne);
      from[0][v] += max(dp[1][ne], dp[0][ne]);
      from[1][v] += dp[0][ne];
    }
    miss[v] = p;
  }

  if (miss[v] != p && miss[v] != n) {
    int ne = mp[{v, miss[v]}];
    dfs(ne);
    from[0][v] += max(dp[1][ne], dp[0][ne]);
    from[1][v] += dp[0][ne];
    miss[v] = n;
  }
  if (miss[v] == n) {
    int nne = mp[{v, p}];
    dp[0][e] += from[0][v] - max(dp[1][nne], dp[0][nne]); // 以 v 為 root 的 MIS - e 反方向看過去的 MIS
    dp[1][e] += from[1][v] - dp[0][nne];
  } else if (miss[v] == p) {
    dp[0][e] += from[0][v];
    dp[1][e] += from[1][v];
  }
}
 
void solve() {
  for (int i = 0; i < n - 1; ++i) {
    adj[a].push_back(b);
    adj[b].push_back(a);
    edges[2 * i] = {a, b};
    edges[2 * i + 1] = {b, a};
    mp[{a, b}] = 2 * i;
    mp[{b, a}] = 2 * i + 1;
  }
  from = vector<vector<int>>(2, vector<int>(n));
  miss = vector<int>(n, -1);
  dp = vector<vector<int>>(2, vector<int>(2 * n - 2, -1));
  for (int i = 0; i < 2 * n - 2; ++i) dfs(i);
}
```

[1984E Shuffle](https://codeforces.com/blog/entry/130252)
