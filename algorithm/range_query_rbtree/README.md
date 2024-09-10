```cpp=
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

Tree<array<ll,2>> t;
t.insert({A[a], a});
t.erase({A[a], a});
t.order_of_key({b, mod}) - t.order_of_key({a-1,mod})
```

[cses Salary Queries](https://cses.fi/problemset/task/1144/)

[code ref](https://usaco.guide/problems/cses-1144-salary-queries/solution)
