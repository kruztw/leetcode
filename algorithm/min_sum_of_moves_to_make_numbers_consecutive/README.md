`a[i]-i`
```cpp=
A  = [0,2,5,6,10,11,13]
A' = [0,1,3,3,6,6,7]

target[3:5] => [0,2,5,6,7,8,13] =>3+6+6-3*3=6
搭配 prefix sum => O(1)
```
[ref](https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/solutions/987362/python-the-trick-and-related-problems/)