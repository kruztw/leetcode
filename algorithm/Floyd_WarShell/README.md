```cpp=
for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)          
            v[i][j] |= v[i][k] & v[k][j];
```