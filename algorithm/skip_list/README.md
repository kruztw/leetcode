```cpp=
int step = sqrt(n);
list<int> l;
vector<list<int>::iterator> skip;

for (auto i = 1; i <= n; ++i) { // [1..n]
    auto it = l.insert(end(l), i);
    if ((i-1) % step == 0) // 不能 == 1 否則 n=3 skip=1 永遠不會進去
        skip.push_back(it);
}

// take ith element to the end
--i; // 從 0 開始
int g = i/step, c = i%step;
auto it = skip[g];
if (!c && next(it) != end(l))
    skip[g] = next(it);

advance(it, idx);

l.splice(end(l), l, it);
while (++g < skip.size())
    skip[g] = next(skip[g]);
```

[ref](https://leetcode.com/problems/design-most-recently-used-queue/)