```cpp=
int kmp(string &s, string &sub) {
    int n = s.length(), m = sub.length();
    vector<int> f(m);
    
    // 計算以每個位置為結尾與開始位置的最長共同 prefix
    int i = 0, j = 1;
    while (j < m) {
        if (sub[j] == sub[i])
            f[j++] = ++i;
        else if (i)
            i = f[i - 1];
        else
            f[j++] = 0;
    }
    
    i = j = 0;
    while (m - i <= n - j) {
        if (sub[i] == s[j])
            i++, j++;
    
        if (i == m) {
            return j - i;
            // i = f[i - 1]; // if keep going, add this line
        } else if (sub[i] != s[j]) {
            if (i) i = f[i-1];
            else j++;
        }
    }
    return -1;
}
```

[ref](https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/)