```cpp=
while (l < r) {
    m = l + (r-l)/2;   // r = m
    m = l + (r-l+1)/2; // l = m 
    if (arr[m] >= target) { 
        l = m;
    } else {
        r = m-1;
    }
}

return l;
```

[leetcode 2187](https://leetcode.com/problems/minimum-time-to-complete-trips/description/)