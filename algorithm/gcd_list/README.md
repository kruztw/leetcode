找尋 nums 子數列可構成幾種 gcd
intuitive: O(N^2^)
gcd list: O(NlogN)

```cpp=
list<pair<int, int>> gcds;
for (int i = 0; i < n; ++i) {
    gcds.push_front(nums[i]);
    for (auto it = begin(gcds); it != end(gcds); ++it) {
        if (it != begin(gcds)) {
            it->second = gcd(it->second, prev(it)->second);
            if (prev(it)->second == it->second)
                gcds.erase(prev(it));
        }
        if (r - it->first + 1 >= k)
            res = max(res, (ps.back() - ps[it->first]) * it->second);
    }
}
```

[ref](https://leetcode.com/problems/maximum-gcd-sum-of-a-subarray/solutions/4318863/sparse-table-vs-gcd-list/)