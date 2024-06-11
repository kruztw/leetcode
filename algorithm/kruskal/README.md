```cpp
vector<int> parents(n+1);
for (int i = 0; i < n; ++i) parents[i] = i;
sort(edgs.begin(), edgse.end(), [](auto &a, auto &b){
    return a[2] < b[2]; 
});

int ret = 0;
for (auto &e: edges)
    if (getP(e[0]) != getP(e[1])) {
        result += e[2];
        merge(e[0], e[1]);
    }
```