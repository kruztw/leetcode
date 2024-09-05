```cpp=
set<ll> adj[1000005];
vector<ll> ans;

void dfs(ll p) {
  while (adj[p].size()) {
    ll x = *adj[p].begin(); adj[p].erase(x);
    adj[x].erase(p);
    dfs(x);
  }
  ans.push_back(p);
}

// n cities, m roads

for (ll i = 1; i <= n; ++i)
  if (adj[i].size()%2) {
    cout <<"IMPOSSIBLE\n";
    return;
}

dfs(1);
if (ans.size()!=m+1) cout << "IMPOSSIBLE\n";
else {
  reverse(ans.begin(), ans.end());
  for (ll i = 0; i <= m; ++i)
    cout << ans[i] << " ";
  cout << "\n";
}
```

[cses Mail Delivery](https://yuihuang.com/cses-1691/)

[ref](https://leetcode.com/problems/valid-arrangement-of-pairs/solutions/1611978/c-eulerian-path-with-explanation/)


