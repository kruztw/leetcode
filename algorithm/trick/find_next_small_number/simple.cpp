#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> a = {2, 0, 3, 1};
    int n = a.size();

    vector<int> stk;
    vector<int> ans(n, -1);
    
    for(int i = 0; i < n; i++) {
        while (!stk.empty() && a[i] < a[stk.back()]) {
            ans[stk.back()] = a[i];
            stk.pop_back();
        }
        stk.push_back(i);
    }

    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}