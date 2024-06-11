```cpp=
// adj: <dst,cost>
int dijkstra(vector<vector<pair<int,int>>> &adj) {
    vector<long> d(n, INT_MAX);
    multimap<long,long> ds;

    d[0] = 0;
    ds.insert({0,0});
    while (ds.size()) {
        auto [v, i] = *ds.begin(); ds.erase(ds.begin());
        if (v != d[i]) continue;
        for (auto [x, w]: adj[i])
            if (v+w < d[x]) {
                d[x] = v+w;
                ds.insert({v+w, x});
            }
    }
}
```