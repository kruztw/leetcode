```cpp=
int rabin_karp(vector<int> &s, vector<int> &t) {
    long x = 31, xn = 1, mod = 1e9 + 7;
    long lenS = s.size(), lenT = t.size(), hashS = 0, hashT = 0;
    for (int i = 0; i < lenT; ++i) {
        hashT = (hashT * x + t[i]) % mod;
        xn = (xn * x) % mod;
    }
    for (int i = 0; i < lenS; ++i) {
        hashS = (hashS * x + s[i]) % mod;
        if (i >= lenT)
            hashS = (mod + hashS - xn * s[i - lenT] % mod) % mod;
        if (i + 1 >= lenT && hashT == hashS)
            return i - lenT + 1;
    }
    return -1;
}
```

[code](https://leetcode.com/problems/number-of-subarrays-that-match-a-pattern-ii/solutions/4708788/rabin-karp/)
[collision check](https://leetcode.com/problems/strings-differ-by-one-character/solutions/802871/rabin-karp-o-nm/)
