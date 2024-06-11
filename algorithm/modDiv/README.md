```cpp=
// ps: a!/b! != (a! %mod)/(b! %mod)
// mod inverse (費馬小定理: b^-1 同餘 b^(mod-2)
long modinv(long a, long mod){
    long b = mod-2, ret = 1;
    for (; b; b >>= 1) {
        if (b&1) ret = ret * a % mod;
        a = a%mod*a%mod%mod;
    }
    return ret;
}
```

[mod inverse leetcode](https://leetcode.com/problems/count-anagrams/discuss/3561617/C%2B%2B-oror-FACTORIAL)
[mod inverse intro](https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/)
