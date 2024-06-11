```cpp=
vector<vector<int>> p;
powerLifting(vector<int>& parent) {
    int n = parent.size();
    p.resize(32, vector<int>(n, -1));
    for (int i = 0; i < n; ++i)
        p[0][i] = parent[i];
        
    for (int i = 1; i < 32; ++i)
        for (int j = 0; j < n; ++j) {
            int np = p[i-1][j];
            if (np != -1)
                p[i][j] = p[i-1][np];
        }
}
    
int getKthAncestor(int node, int k) {
    for (int i = 0; i < 32; ++i)
        if (k & (1<<i)) {
            node = p[i][node];
            if (node == -1)
                return -1;
        }
    return node;
}
```

[leetcode 1483](https://leetcode.com/problems/kth-ancestor-of-a-tree-node/description/)