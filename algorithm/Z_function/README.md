計算每個位置與開始位置的最長共同 prefix

Z[i] = j => A[0:j) == A[i:i+j-1]

假設 Z[i] = j，怎麼計算 z[i'] ?  (i' > i)

case1: i+j < i' : Z[i'] = 0 (重新計算)
case2: i+j > i' : Z[i'] = min(j-i'+1, Z[i-i'])

對於 case2 來說，順序是 i ~ i' ~ (i+j)
把 i 般到 0 變成 0 ~ k ~ j (k = i'-i) // A[0:j) == A[i:i+j)

如果 k+Z[k] 不到 j，則 Z[i'] 從 Z[k] 開始
否則 Z[i'] 從 j-i'+1 開始 (A[0:k) == A[k:j), 無法確定 A[i+j:] 是否等於 A[i':])

```cpp=
void getZ(string &s, vector<int> &Z) {
    int best = 0;
    Z[0] = 0;
    for(int i = 1; s[i]; i++) {
        if (best + Z[best] < i) Z[i] = 0;
        else Z[i] = min(best+Z[best]-i, Z[i-best]);
        while(s[i+Z[i]] == s[Z[i]]) Z[i]++;
        if(i+Z[i] > best+Z[best]) best = i;
    }
}
```