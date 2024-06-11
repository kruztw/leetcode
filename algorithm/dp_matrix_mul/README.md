```
// dp[0][0] = 1, dp[0][1] = 0
// dp[i][0] = dp[i-1][0]*a + dp[i-1][1]*b
// dp[i][1] = dp[i-1][0]*c + dp[i-1][1]*d

auto dp = pow({{a, b}, {c, d}}, k)[0];
vector<vector<int>> pow(vector<vector<int>> &a, long long y) {
    int n = a.size();
    vector<vector<int>> r(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        r[i][i] = 1;

    auto x = a;
    for (; y; y >>= 1) {
        if (y & 1) r = mul(r, x);
        x = mul(x, x);
    }
    return r;
}

vector<vector<int>> mul(vector<vector<int>> &a, vector<vector<int>> &b) {
    const int m = a.size(), n = a[0].size(), p = b[0].size();
    vector<vector<int>> r(m, vector<int>(p));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < p; ++k)
                r[i][k] = (mod + r[i][k] + a[i][j]*b[j][k]%mod)%mod;
    return r;
}
```

[ref](https://leetcode.com/problems/string-transformation/solutions/4024648/solutions-with-c-java-and-python/)