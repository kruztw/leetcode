```cpp=
// 一點到多點
// edges: <src,dst,cost>
#define mx (LLONG_MAX/3);
vector<long long> d2(n, mx);
void bf2(vector<vector<vector<long long>>> &edges, int a, int b) { // bf2: d2[k] != mx => a can reach k
    d[a] = 0;
    for (int i = 0; i < n-1; ++i)
        for (auto &e: edges) {
            long long u = e[0], v = e[1], w = e[2];
            d[v] = min(d[v], d[u] + w);
        }
}

int bf(vector<vector<vector<long long>>> &edges, int a, int b) {
    vector<long long> d(n, mx);
    d[a] = 0;

    for (int i = 0; i < n-1; ++i)
        for (auto &e: edges) {
            long long u = e[0], v = e[1], w = e[2];
            d[v] = min(d[v], d[u] + w);
        }
        
    for (auto &e: edges) {
        long long u = e[0], v = e[1], w = e[2];
        if (d[u] + w < d[v] && d[v]!=mx && d2[v]!=mx) // a-b contains negative cycle which includes node v
            return -1;
    }
    
    return d[b] == mx ? -1 : d[b];
}

bf2(redges, dst, src);
bf(edges, src, dst);

// 多點到多點
void bf(vector<vector<vector<long long>>> &adj) {
    vector<vector<long long>> d(n, vector<long long>(n, LLONG_MAX/3));
    for (int i = 0; i < n; ++i)
        d[i][i] = 0;

    for (int i = 0; i < n-1; ++i) {
        for (auto &e: edges) {
            long long u = e[0], v = e[1], w = e[2];
            for (int f = 0; f < n; ++f) {
                d[f][v] = min(d[f][v], d[f][u] + w);
                // 無向圖
                d[f][u] = min(d[f][u], d[f][v] + w);
            }
        }
    }
}
```

[cses high score](https://cses.fi/problemset/task/1673/)
