```cpp=
vector<int> sa(string &s, vector<int> &pos, int len) {
    unordered_map<string, vector<int>> d;
    for (int p: pos) {
        string key = s.substr(p, len);
        d[key].push_back(p);
    }

    vector<int> ret;
    for (auto &kv : d) {
        vector<int> &v = kv.second;
        if (v.size() > 1) {
            auto x = sa(s, v, len*2);
            ret.insert(ret.end(), x.begin(), x.end());
        } else {
            ret.push_back(v[0]);
        }
    }
    return ret;
}
```

[ref](https://leetcode.com/problems/number-of-distinct-substrings-in-a-string/solutions/1010936/python-suffix-array-lcp-o-n-logn/)