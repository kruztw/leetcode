```cpp=
vector<int> lcp(string &s, vector<int> &sa) {
    int n = sa.size();
    vector<int> rank(n);
    for (int i = 0; i < n; ++i)
        rank[sa[i]] = i; // rank[i]: 從 i 開始的 suffix 在 sa 的哪個位置

    int k = 0;
    vector<int> ret(n);
    for (int i = 0; i < n; ++i) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = sa[rank[i] + 1]; // 跟下面一個比
        while(i+k<n && j+k<n && s[i+k] == s[j+k])
            ++k;
        
        ret[rank[i]] = k;
        if (k > 0) --k; // 沒設回 0 => O(n)
    }
    return ret;
}
```

[ref](https://leetcode.com/problems/number-of-distinct-substrings-in-a-string/solutions/1010936/python-suffix-array-lcp-o-n-logn/)