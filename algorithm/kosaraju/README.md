```cpp=
void dfs1(vector<vector<int>> &adj, vector<bool> &visit, stack<int> &s, int cur) {
    if (visit[cur])
        return;

    visit[cur] = true;
    for (auto x: adj[cur])
        dfs1(adj, visit, s, x);
    s.push(cur);
}

void dfs2(vector<vector<int>> &adj, vector<bool> &visit, int cur) {
    if (visit[cur])
        return;

    cout << cur << " ";
    visit[cur] = true;
    for (auto x: adj[cur])
        dfs2(adj, visit, x);
}

void kosaraju(int n, vector<vector<int>> &adj) {
    stack<int> s;
    vector<bool> visit(n);

    for (int i = 0; i < n; ++i)
        if (!visit[i])
            dfs1(adj, visit, s, i);

    vector<vector<int>> radj(n);
    for (int i = 0; i < n; ++i)
        for (auto x: adj[i])
            radj[x].push_back(i);

    vector<bool> visit2(n);
    while (!s.empty()) {
        int cur = s.top();
        s.pop();

        if (visit2[cur])
            continue;

        dfs2(radj, visit2, cur);
        cout << endl;
    }
}   
```