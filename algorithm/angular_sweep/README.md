```cpp=
class Solution {
public:
    int numPoints(vector<vector<int>>& p, int r) {
        int n = p.size();
        vector<vector<double>> d(n, vector<double>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = d[j][i] = sqrt((p[i][0]-p[j][0])*(p[i][0]-p[j][0]) + (p[i][1]-p[j][1])*(p[i][1]-p[j][1]));
        
        int ans = 1;
        for (int i=0; i<n; ++i) {
            vector<pair<double, bool>> angles;    
            for (int j=0; j<n; ++j)
                if (j != i && d[i][j] <= 2 * r) {
                    // A: pq and x axis    => atan2(dy/dx) => atan2(tan) => theta
                    // B: pq and diameter  => acos(pq/diameter) => acos(cos) => theta
                    double A = atan2(p[j][1] - p[i][1], p[j][0] - p[i][0]);
                    double B = acos(d[i][j] / (2.0 * r));
                    double alpha = A-B, beta = A+B; // alpha: in, beta: out
                    angles.push_back({alpha, false});
                    angles.push_back({beta, true});
                }
            
            sort(angles.begin(), angles.end()); 
            
            int cnt = 1;
            for (auto it=angles.begin(); it!=angles.end(); ++it) {
                if ((*it).second == false) cnt++;
                else cnt--;
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
// https://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/
// 二張圖的 angleA angleB 要一樣大才對
// O 代表圓心，上圖失真
```

[ref](https://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/solutions/636416/c-o-n-2logn-angular-sweep-with-picture/)
