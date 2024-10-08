```
4*N => lazy needs another layer
   O
 O   O    <=arr (N=2)
O O O O   <=update arr will update arr child's lazy
```

```cpp=
const int N = 100000;
int tree[4*N], lazy[4*N], arr[N+1], mod = 1e9 + 7;
long long query(int l, int r, int p=1, int tl=0, int tr=N) { // note: tl==tr -> l==r ; l==r doesn't mean tl==tr
    if (l > r)
        return 0;
    if(l == tl && r == tr)
        return (tree[p] + lazy[p]*(r-l+1LL)) % mod;
        return (tree[p] + lazy[p]) % mod; // Range Max Query
        
    int tm = (tl+tr)/2;
    int ql = query(l, min(tm, r), 2*p, tl, tm); 
    int qr = query(max(l, tm+1), r, 2*p+1, tm+1, tr); 
    return lazy[p]*(r-l+1LL) + ql + qr;
    return lazy[p] + max(ql, qr); // RMQ
}

void update(int l, int r, int v, int p=1, int tl=0, int tr=N) {
    if (l == tl && r == tr)
        lazy[p] += v;
    else if (l <= r) {
        lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
        lazy[p] = 0;
        int tm = (tl + tr)/2;
        update(l, min(tm, r), v, 2*p, tl, tm);
        update(max(l, tm+1), r, v, 2*p+1, tm+1, tr);
        int ql = query(tl, tm, 2*p, tl, tm);
        int qr = query(tm+1, tr, 2*p+1, tm+1, tr);
        tree[p] = ql + qr
        tree[p] = max(ql, qr); // RMQ
    }
}
// 如果要設定初始值(arr)的話
void build_tree(int p = 1, int tl = 0, int tr = N) {
    if(tl > tr) return;
    if(tl == tr) {
        tree[p] = arr[tl];
        return;
    }
    int tm = (tl+tr)/2;
    build_tree(2*p, tl, tm);
    build_tree(2*p+1, tm+1, tr);
    tree[p] = max(tree[p*2], tree[p*2+1]);
}
```

[code ref](https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-ii/)
[ref](https://www.geeksforgeeks.org/lazy-propagation-in-segment-tree/)
[rmq code ref](https://leetcode.com/problems/block-placement-queries/submissions/1267778143/)
[tree node 存 sturct](https://leetcode.com/problems/maximum-sum-of-subsequence-with-non-adjacent-elements/submissions/1268225804/)

```cpp=
const int N = 100000;
int tt[4*N], mod = 1e9 + 7;
long long query(int l, int r, int p=1, int tl=0, int tr=N) {
    if (l>tr || r<tl) return 0;
    if (l<=tl && r>=tr) return tt[p];
        
    ll tm = (tl+tr)/2;
    ll ql = query(l, r, target, 2*p, tl, tm);
    ll qr = query(l, r, target, 2*p+1, tm+1, tr);

    return max(ql, qr);
}

void update(ll i, ll v, ll p = 1, ll l = 1, ll r = n) {
  if (l==r) {
    tt[p] = v;
    return;
  }

  ll m = (l+r)/2;
  if (i<=m) update(i, v, 2*p, l, m);
  else update(i, v, 2*p+1, m+1, r);
  tt[p] = max(tt[2*p], tt[2*p+1]);
}

void build_tree(vector<int> &A, int p = 1, int tl = 0, int tr = N) {
    if(tl==tr) {
        tt[p] = A[tl];
        return;
    }
    int tm = (tl+tr)/2;
    build_tree(A, 2*p, tl, tm);
    build_tree(A, 2*p+1, tm+1, tr);
    tt[p] = max(tt[2*p], tt[2*p+1]);
}

build_tree(A, 1, 0, A.size()-1); // tr 一定要一樣
query(l, r, 1, 0, A.size()-1);   // tr 一定要一樣
```

[cses Prefix Sum Queries](https://cses.fi/problemset/task/2166/)

[ref](https://usaco.guide/problems/cses-2166-prefix-sum-queries/solution)
