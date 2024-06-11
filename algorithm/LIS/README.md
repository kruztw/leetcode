```cpp=
/* decreasing
 * reverse(v.begin(), v.end());
 * for i in 0 ~ n-1:
 *   LDS[n-i-1] = ...
 */
vector<int> v;
vector<int> LIS(n)
for (int i = 0; i < n; ++i) {
    auto it = lower_bound(v.begin(), v.end(), nums[i]);
    if (it == v.end()) {
        v.push_back(nums[i]);
        LIS[i] = v.size();
    } else {
        LIS[i] = it - v.begin();
        *it = nums[i];
    }
}

// 想要找出順序, 則必須另存來源 (parent)

void backtrace(vector<int> &nums, vector<int> &parent, int cur) {
    if (cur == parent[cur])
        return;
    helper(nums, parent, parent[cur]);
}

int n = nums.size();
vector<pair<int,int>> v;
vector<int> parent(n, -1);

for (int i = 0; i < n; ++i) {
    auto it = lower_bound(v.begin(), v.end(), nums[i]);
    if (it == v.end()) {
        parent[i] = v.size() ? v.back().second : i;
        v.push_back({nums[i],i});
    } else if (it == v.begin()) {
        parent[i] = i;
        v[0] = {nums[i], i};
    } else {
        int idx = it - v.begin();
        parent[i] = v[idx-1].second;
        v[idx] = {nums[i], i};
    }
}

backtrace(nums, parent, v.back().second);
```