// https://leetcode.com/problems/find-the-k-sum-of-an-array/

#include <bits/stdc++.h>

using namespace std;

void big_2_small(vector<int> &nums) {
        int n = nums.size();
        
        vector<long> v(n);
        for (int i = 0; i < n; ++i)
            v[i] = abs(nums[i]);
        
        sort(v.begin(), v.end());
        
        long sum = 0;
        for (int i = 0; i < n; ++i)
            sum += nums[i] > 0 ? nums[i] : 0;
        
        cout << sum << " ";;
        
        priority_queue<pair<long, int>> pq;
        pq.push({sum-v[0], 0});
        while (!pq.empty()) {
            auto [sum, idx] = pq.top();
            pq.pop();
            
            cout << sum << " ";
            
            if (idx+1 < n) {
                pq.push({sum-v[idx+1], idx+1});
                pq.push({sum-v[idx+1]+v[idx], idx+1});
            }
        }
	cout << endl;
}
    
void small_2_big(vector<int> &nums) {
    int n = nums.size();
    
    vector<long> v(n);
    for (int i = 0; i < n; ++i)
        v[i] = abs(nums[i]);
    
    sort(v.begin(), v.end());
    
    long sum = 0;
    for (int i = 0; i < n; ++i)
        sum += nums[i] < 0 ? nums[i] : 0;
    
    cout << sum << endl;
    
    priority_queue<pair<long, int>> pq; // 大到小, 所以塞負的
    pq.push({-(sum+v[0]), 0});
    while (!pq.empty()) {
        auto [sum, idx] = pq.top();
        sum *= -1;
        
        pq.pop();
        
        cout << sum << " ";
        
        if (idx+1 < n) {
            pq.push({-(sum+v[idx+1]), idx+1});
            pq.push({-(sum+v[idx+1]-v[idx]), idx+1});
        }
    }
    cout << endl;
}

int main() {
	vector<int> nums = {1,-2,3,4,-10,12};
	big_2_small(nums);
	small_2_big(nums);
}
