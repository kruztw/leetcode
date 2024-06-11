計算二著色最大配對

```cpp=
// 一維
bool dfs(vector<vector<int>>& grid, int r, vector<int> &visit, vector<int> &match) {
    for (int i = 0; i < grid[0].size(); i++)
        if (grid[r][i] && !visit[i]) {
            visit[i] = 1;
            if (match[i] == -1 || dfs(match[i], grid, visit, match)) {
                match[i] = r;
                return true;
            }
        }
        
    return false;
}
    
int hungarian1(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> match(n, -1);
    int ans = 0;

    for (int i = 0; i < m; i++) {
        vector<int> visit(n);
        ans += dfs(i, grid, visit, match);
    }

    return ans;
}

// 二維
int hungarian2(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> match(m, vector<int>(n, -1));
    vector<vector<int>> visit(m, vector<int>(n, -1));

    int ans = 0;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (grid[i][j] && match[i][j] == -1) {
                visit[i][j] = i*n+j;
                ans += dfs(grid,i, j, visit[i][j], match, visit);
            }
    return ans;
}
int dfs(vector<vector<int>> &grid, int r, int c, int v, vector<vector<int>> &match, vector<vector<int>> &visit) {
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < 4; ++i) {
        int nr = r + dirs[i], nc = c + dirs[i+1];
        if (nr < 0 || nc < 0 || nr >= m || nc >= n || visit[nr][nc] == v || !grid[nr][nc])
            continue;
            
        visit[nr][nc] = v;
        if (match[nr][nc] == -1 || dfs(grid, match[nr][nc]/n, match[nr][nc]%n, v, match, visit)) {
            match[nr][nc] = r*n + c;
            match[r][c] = nr*n + nc;
            return true;
        }
    }
    return false;
}
```

[一維](https://leetcode.com/problems/maximum-number-of-accepted-invitations/submissions/1263832687/)
[二維](https://leetcode.com/problems/minimum-operations-to-remove-adjacent-ones-in-matrix/)
