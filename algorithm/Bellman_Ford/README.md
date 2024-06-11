```cpp=
// 一點到多點
// edges: <src,dst,cost>
int bf(vector<vector<vector<int>>> &edges, int i, int j) {
    vector<long> d(n, INT_MAX);
    d[src] = 0;
        
    for (int i = 0; i < n-1; ++i)
        for (auto &e: edges) {
            int u = e[0], v = e[1], w = e[2];
            d[v] = min(d[v], d[u] + w);
        }
        
    for (auto &e: edges) {
        int u = e[0], v = e[1], w = e[2];
        if (d[u] + w < d[v]) // negative cycle
            return INT_MIN;
    }
    
    return d[j] == INT_MAX ? -1 : d[j];
}

// 多點到多點
void bf(vector<vector<vector<int>>> &adj) {
    vector<vector<long>> d(n, vector<long>(n, INT_MAX));
    for (int i = 0; i < n; ++i)
        d[i][i] = 0;

    for (int i = 0; i < n-1; ++i) {
        for (auto &e: edges) {
            int u = e[0], v = e[1], w = e[2];
            for (int f = 0; f < n; ++f) {
                d[f][v] = min(d[f][v], d[f][u] + w);
                // 無向圖
                d[f][u] = min(d[f][u], d[f][v] + w);
            }
        }
    }
}
```