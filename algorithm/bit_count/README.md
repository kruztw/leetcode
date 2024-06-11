```cpp=
for (int i = 0; i < 32; i++) {
    long p = (1ll<<(i+1)); // 每 p 個一組
    long cur = (n+1)/p * (1ll<<i); // 每組幾個
    cur += max(0ll, (n+1)%p - (1ll<<i)); // 未滿 1 組的部分
}
```

[ref](https://leetcode.com/problems/find-products-of-elements-of-big-array/)

```cpp=
__builtin_popcount, __builtin_popcountll
```