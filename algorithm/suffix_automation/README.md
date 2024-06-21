```cpp=
struct state {
    int len = 0, link = -1;
    unordered_map<int, int> next;
};

void sa_extend(vector<state> &st, int c, int &sz, int &last) const {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

vector<state> sa_build(vector<int> &v) {
    vector<state> st(v.size() * 2);
    int sz = 1, last = 0;
    for (auto x:  v)
        sa_extend(st, x, sz, last);
    return st;
}

int longestCommonSubpath(int n, vector<vector<int>>& paths) {
    auto st = sa_build(paths[0]);
    int res = 0;
    for (int i = 1; i < paths.size(); ++i) {
        vector<int> next;
        int v = 0, l = 0;
        for (int j = 0; j <= paths[i].size(); ++j) {
            if (j == paths[i].size() || !st[v].next.count(paths[i][j])) {
                if (i == paths.size() - 1)
                    res = max(res, l);
                else {
                    next.insert(end(next), begin(paths[i]) + j - l, begin(paths[i]) + j);
                    next.push_back(100001);
                }
            }
            while (j < paths[i].size() && v && !st[v].next.count(paths[i][j])) {
                v = st[v].link;
                l = st[v].len;
            }
            if (j < paths[i].size() && st[v].next.count(paths[i][j])) {
                v = st[v].next[paths[i][j]];
                l++;
            }
        }
        st = sa_build(next);
    }
    return res;
}
```

[ref](https://leetcode.com/problems/longest-common-subpath/solutions/1314826/rolling-hash-vs-suffix-automation/)
