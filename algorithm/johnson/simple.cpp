#include <bits/stdc++.h>

using namespace std;
using PII = pair<int, int>;

void dijkstra(int V, vector<vector<int>> &E, int src, vector<vector<int>> &res) {
    vector<vector<PII>> adj(V+1);
    for (auto e: E)
        adj[e[0]].push_back({e[1], e[2]});

    res[src][src] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.emplace(0, src);

    while (!pq.empty()) {
        auto [c, s] = pq.top();
        pq.pop();

        if (c > res[src][s])
            continue;

        for (auto e: adj[s])
            if (c + e.second < res[src][e.first])
                pq.emplace(res[src][e.first] = c + e.second, e.first);
    }

}

void BF(int V, vector<vector<int>> &E, vector<int> &h) {
    h.push_back(0); // point V is the supper point

    for (int i = 0; i < V; ++i)
        E.push_back({V, i, 0});

    for (int i = 0; i <= V; ++i)
        for (auto e: E)
            h[e[1]] = min(h[e[1]], h[e[0]] + e[2]);
}

int main() {
    int V = 4;
    vector<vector<int>> E = {{0, 1, 1}, {1, 2, -1}, {2, 3, 1}, {3, 0, 2}};
    vector<int> h(V, INT_MAX/2);
    vector<vector<int>> d(V, vector<int>(V, INT_MAX/2));

    BF(V, E, h);

    for (auto &e: E)
        if ((e[2] = e[2] + h[e[0]] - h[e[1]]) < 0) // detect negative loop
            return -1;

    for (int i = 0; i < V; ++i)
        dijkstra(V, E, i, d);

    for (int i = 0; i < V; ++i)
        for (int j = i+1; j < V; ++j)
            cout << i << " - " << j << " : " << d[i][j] - h[i] + h[j] << endl;
}

/*
0 --- 1 ---> 1
^            |
|            -1
2            |
|            v
3 <--- 1 --- 2
*/
