```cpp=
# every bits represent a value, left shift x means plus x
# using mask to implement group add

bitset<50000> dp, mask; 
dp[0] = true; // dp[i]: can reach value i

int maskP = 0;
for (int x: A)
    if (maskP < x) {
        while (maskP < x)
            mask[maskP++] = true;
        dp |= (dp & mask) << x; // group add
    }
```

[leetcode 3181](https://leetcode.com/problems/maximum-total-reward-using-operations-ii/description/)