```cpp=
int m = s1.length();
int n = s2.length();
        
vector<vector<int>> dp(m+1, vector<int>(n+1));
for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) {
        if (s1[i-1] == s2[j-1])
            dp[i][j] = dp[i-1][j-1] + 1;
        dp[i][j] = max(max(dp[i][j], dp[i-1][j]), dp[i][j-1]);
    }
```