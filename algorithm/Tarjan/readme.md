```cpp=
#include <bits/stdc++.h>

using namespace std;

/* (low, time)
(1,1)              (4,4)
     O --------------O
    / \             / \
   O - O           O - O
(1,2)  (1,3)   (4,5)    (4,6)
*/

void Tarjan(vector<vector<int>> &adj, int cur, int prev, int &t, vector<int> &low, vector<int> &time) {
        time[cur] = low[cur] = t++;
        for (auto x: adj[cur]) {
                if (time[x] == 0) {
                        Tarjan(adj, x, cur, t, low, time);
                        low[cur] = min(low[cur], low[x]);
                } else if (x != prev) {
                        low[cur] = min(low[cur], time[x]);
                }

                if (low[x] > time[cur])
                        cout << "bridge: " << cur << " " << x << endl;
        }
}

int main() {
        int n = 6;
        vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {0, 3}, {3, 4}, {4, 5}, {5, 3}};
        vector<vector<int>> adj(n);

        for (auto e: edges) {
                adj[e[0]].push_back(e[1]);
                adj[e[1]].push_back(e[0]);
        }

        vector<int> time(n);
        vector<int> low(n);
        int t = 1;
        Tarjan(adj, 0, -1, t, low, time);

        return 0;
}
```
