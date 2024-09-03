```cpp=
// non-direcitonal
/* (low, time)
(1,1)              (4,4)
     O --------------O
    / \             / \
   O - O           O - O
(1,2)  (1,3)   (4,5)    (4,6)
*/

void Tarjan(vector<vector<int>> &adj, int p, int pp, int &t, vector<int> &low, vector<int> &ts) {
        time[p] = low[p] = t++;
        for (auto x: adj[p]) {
                if (time[x] == 0) {
                        Tarjan(adj, x, p, t, low, ts);
                        low[p] = min(low[p], low[x]);
                } else if (x != pp) {
                        low[p] = min(low[p], ts[x]);
                }

                if (low[x] > ts[p])
                        cout << "bridge: " << p << " " << x << endl;
        }
}

// direcitonal
ll t, scc;
ll g[100005], stk[100005], low[100005], ts[100005];
stack<ll> st;

void Tarjan(vector<vector<ll>> &adj, ll p) {
  ts[p] = low[p] = ++t;
  st.push(p);
  stk[p] = 1;

  for (auto x: adj[p]) {
    if (!ts[x]) {
      Tarjan(adj, x);
      low[p] = min(low[p], low[x]);
    } else if (stk[x]) {
      low[p] = min(low[p], ts[x]);
    }
  }

  if (low[p]==ts[p]) {
    g[p] = ++scc;
    if (ans[0]==-1) ans[0] = p+1;
    else if (ans[1]==-1) ans[1] = p+1;

    ll nxt = -1;
    while (nxt!=p) {
      nxt = st.top(); st.pop();
      g[nxt] = scc;
      stk[nxt] = 0;
    }
  }
}
```
[code](https://web.ntnu.edu.tw/~algo/ConnectedGraph.html)
[cses Flight Routes Check](https://cses.fi/problemset/task/1682/)
