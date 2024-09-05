```cpp=
// postorder !! {1,3},{1,2},{2,1}
void euler(vector<vector<int>> &adj, int p, vector<vector<int>> &path) {
    while (adj[p].size()) {
        int x = adj[p].back();
        adj[p].pop_back();
        dfs(adj, x, ans);
        path.push_back({p, x});
    }
}

start = 0; // any node
for (int i = 0; i < n; ++i)
  if (out[i] - in[i] == 1)
    start = i;
  
vector<vector<int>> path;
euler(adj, start, path);
reverse(path.begin(), path.end());
```

[ref](https://leetcode.com/problems/valid-arrangement-of-pairs/solutions/1611978/c-eulerian-path-with-explanation/)
