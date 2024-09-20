```cpp=
ll modPow(ll a, ll b, ll mod) {
    ll ret = 1;
    for (; b; b >>= 1) {
        if (b&1) ret = ret * a % mod;
        a = a%mod*a%mod%mod;
    }
    return ret;
}
```
