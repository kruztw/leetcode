使用時機: 對子數列進行多次操作

[1,2,3,4,5] 將 [2:4] 加 1 => [1,3,4,5,5]
unaccumlated array: 
[1,1,1,1,1] 將 [2:4] 加 1 => [1,2,1,0,1]
prefix => [1,3,4,5,5]


```cpp
A[0] = arr[0]
A[i] = arr[i] - arr[i-1]
for(auto x: ranges) {
    A[x[0]]++, A[x[1]]--;
}
return prefix(A);
```

[leetcode 2790](https://leetcode.com/problems/maximum-number-of-groups-with-increasing-length/description/)