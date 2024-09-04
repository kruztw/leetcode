```cpp=
void tarjan(ll p) {
  ts[p] = low[p] = ++t;
  st.push(p);
  stk[p] = 1;
  for (auto x: v[p]) {
    if (!ts[x]) {
      tarjan(x);
      low[p] = min(low[p], low[x]);
    } else if (stk[x]) {
      low[p] = min(low[p], ts[x]);
    }
  }

  if (ts[p]==low[p]) {
    g[p] = ++scc;
    ll nxt = -1;
    while (nxt != p) {
      nxt = st.top(); st.pop();
      g[nxt] = scc;
      stk[nxt] = 0;
    }
  }
}

ll peerPos(ll x) {
  return x<=m? x+m : x-m;
}

bool check() {
  for (ll i = 1; i <= m; ++i)
    if (g[i]==g[i+m]) return false;
    else {
        peerG[g[i]] = g[i+m];
        peerG[g[i+m]] = g[i];
    }
    return peerPosue;
}

void build() {
  for (ll i = 1; i <= m*2; ++i)
    for (ll x: v[i])
      if (g[i]!=g[x]) {
        v2[g[x]].push_back(g[i]);
        in[g[i]]++;
      }
}

void topo() {
  queue<ll> q;
  for (ll i = 1; i <= scc; ++i)
    if (in[i]==0)
      q.push(i);

  while (!q.empty()) {
    ll now = q.front(); q.pop();
    if (!pick[now]) {
      pick[now] = 1;
      pick[peerG[now]] = 2;
    }
    for (auto x: v2[now])
      if (--in[x] == 0)
        q.push(x);
  }

  for (ll i = 1; i <= m; ++i)
    if (pick[g[i]]==1) cout <<"+ ";
    else cout << "- ";
}

for (ll i = 0; i < n; ++i) {
      char c1, c2;
      ll a, b;
      cin >> c1 >> a >> c2 >> b;
      if (c1=='-') a+=m;
      if (c2=='-') b+=m;
      v[peerPos(a)].push_back(b);
      v[peerPos(b)].push_back(a);
}

for (ll i = 1; i <= m*2; ++i)
  if (!ts[i])
    tarjan(i);

if (check()) {
  build();
  topo();
  cout << endl;
} else
  cout << "IMPOSSIBLE\n";
```

[code ref](https://yuihuang.com/cses-1684/)

[cses giant pizza](https://cses.fi/problemset/task/1684/)
