```cpp=
bool isConvex(vector<vector<int>>& p) {
    int n = p.size(), prev = 0;
    for (long i = 0; i < n; ++i) {
        int cur = det({p[i], p[(i+1)%n], p[(i+2)%n]});
        if (cur*prev < 0) return false; 
        else prev = cur;
    }

    return true;
}

ll det(const vector<vector<int>> &A) { // determinant
    return (A[1][0]-A[0][0])*(A[2][1]-A[0][1]) - (A[1][1]-A[0][1])*(A[2][0]-A[0][0]);
}
```

[leetcode 469](https://leetcode.com/problems/convex-polygon/solutions/95590/c-5-liner-o-n-checking-convexity-with-cross-product-of-adjacent-vectors-detailed-explanation/)
