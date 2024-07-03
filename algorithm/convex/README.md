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

## convex hull

```cpp=
int cross(vector<int> &o, vector<int> &a, vector<int> &b) {
  return (a[0]-o[0])*(b[1]-o[1]) - (a[1]-o[1])*(b[0]-o[0]);
}

int d(vector<int> &a, vector<int> &b) {
  return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
}

bool far(vector<int> &o, vector<int> &a, vector<int> &b) {
  return d(o,a) > d(o,b);
}

int main() {
  int start = 0;
  vector<vector<int>> P = {{0,2},{2,0},{0,0},{2,2},{1,1}};

  int n = P.size();
  for (int i = 0; i < n; ++i)
    if (P[i][1]<P[start][1] || (P[i][1]==P[start][1] && P[i][0]<P[start][0]))
      start = i;

  vector<vector<int>> ch;
  ch.push_back(P[start]);

  int cur = start;
  while (true) {
    int next = cur;
    for (int i = 0; i < n; ++i) {
      int c = cross(ch.back(), P[i], P[next]);
      if (c>0 || (c==0 && far(ch.back(), P[i], P[next])))
        next = i;
    }

    if (next==start) break;
    ch.push_back(P[next]);
    cur = next;
  }
}
```

[ref](https://web.ntnu.edu.tw/~algo/ConvexHull.html)
