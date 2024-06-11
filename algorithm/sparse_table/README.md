鎖長度: 從 i 開始往後 2^j^
使用時機: range query

```cpp=
// MRQ (Minimun Range Query)
vector<vector<int>> st({A}); // st[i][j]: j ~ j+2^i-1
void buildSparseTable(long n) {
    for (int i = 1; (1 << i) <= n; ++i) { // 長度
        st.push_back({});
        for (int j = 0; j + (1 << i) <= n; ++j) // 位置
            st[i].push_back(min(st[i-1][j], st[i-1][j+(1<<(i-1))]));
    }
}

int query(long l, long r) {
    int i = bit_width(r-l+1) - 1; // 長度
    return min(st[i][l], st[i][r-(1<<i)+1]);
} 
```

[ref](https://www.geeksforgeeks.org/sparse-table/)
[leetcode 2941](https://leetcode.com/problems/maximum-gcd-sum-of-a-subarray/description/)