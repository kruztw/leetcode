```CPP=
ll dp[1000][1000];
ll mod = 1e9 + 7;
ll stirling(ll N, ll M) { // N 個人分 M 組，且每組至少 1 人
  if (M == 0 || M > N) return 0;
  if (M == 1 || M == N) return 1;
  if (dp[N][M] != -1) return dp[N][M];

  return dp[N][M] = (M*stirling(N - 1, M)%mod + stirling(N - 1, M - 1))%mod;
}
```
[leetcode 3317](https://leetcode.com/problems/find-the-number-of-possible-ways-for-an-event/description/)
