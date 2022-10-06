// https://leetcode.com/problems/min-cost-to-connect-all-points/

#include <bits/stdc++.h>

using namespace std;

int prime(vector<vector<int>>& points) {
    int n = points.size();
    auto dist = [](vector<int>& pi, vector<int>& pj) {
        return abs(pi[0] - pj[0]) + abs(pi[1] - pj[1]);
    };
    
    // 各點到第 0 點的距離
    vector<int> d(n, INT_MAX); 
    for (int i = 1; i < n; ++i)
        d[i] = dist(points[0], points[i]);

    int ans = 0;
    for (int i = 1; i < n; ++i) { // 納入第 i 個點
        auto it = min_element(begin(d), end(d)); // 選最短邊
        const int v = distance(begin(d), it); // 新納入的點
        
        ans += d[v];
        d[v] = INT_MAX; // 已經是 spanning tree 的點

        for (int j = 0; j < n; ++j) { // 各點到 v 的距離
            if (d[j] == INT_MAX) 
                continue;
            d[j] = min(d[j], dist(points[j], points[v]));
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> points = {{3,12},{-2,5},{-4,1}};
    int ans = prime(points);
    cout << ans << endl;
}
