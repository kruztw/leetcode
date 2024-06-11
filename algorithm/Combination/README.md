```cpp=
mod = 1e9 + 7;

long f[10001], inv[10001];
f[0]=1, inv[0]=1;
for(int i = 1; i <= 1e4; ++i)
    f[i]=(f[i-1]*i)%mod, inv[i]=modinv(f[i]);

long C(long a,long b) { 
    return f[a]*inv[b]%mod*inv[a-b]%mod;
}

vector<vector<int>> c(n+1, vector<int>(n+1));

int C(int a, int b) { // C(a, b)
    if (a == b || b == 0)
        return 1;
    
    if (!c[a][b])
        c[a][b] = (C(a-1,b-1)+C(a-1,b))%mod;
    
    return c[a][b];
}
```