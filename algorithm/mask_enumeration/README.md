```cpp=
int mask = 14; // b01110
int i = mask;
for ( ; i ; i = (i-1)&mask)
    cout << i << endl;
```
[ref](https://leetcode.com/problems/parallel-courses-ii/solutions/719159/dp-solution-with-memoization-and-bitmasks-with-c-code-20-ms-runtime/)