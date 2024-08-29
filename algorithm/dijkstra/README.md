```cpp=
// adj: <dst,cost>
int dijkstra(vector<vector<pair<int,int>>> &adj) {
    vector<ll> d(n, INT_MAX);
    multimap<ll,ll> ds;

    d[0] = 0;
    ds.insert({0,0});
    while (ds.size()) {
        auto [v, f] = *ds.begin(); ds.erase(ds.begin());
        if (v != d[f]) continue;
        for (auto [t, w]: adj[f])
            if (v+w < d[t]) {
                d[t] = v+w;
                ds.insert({v+w, t});
            }
    }
}

// version2
vector<ll> d(n, LLONG_MAX);
multimap<ll,ll> ds;

ds.insert({0,0});
while (ds.size()) {
    auto [v,f] = *ds.begin(); ds.erase(ds.begin());
    if (d[f]!=LLONG_MAX) continue;

    d[f] = w;
    for (auto [t,w]: adj[f])
        ds.insert({v+w,x});
}
```
