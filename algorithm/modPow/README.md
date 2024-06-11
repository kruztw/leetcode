```cpp=
long modPow(long a, long b, long mod) {
    long ret = 1;
    for (; b; b >>= 1) {
        if (b&1) ret = ret * a % mod;
        a = a%mod*a%mod%mod;
    }
    return ret;
}
```