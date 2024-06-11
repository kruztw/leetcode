```cpp=
// 法一: manacher's algorithm O(n)
string manacher(string &s) {
    int len = s.size(), n = 2*len+1;
    vector<int> lps(n);
    int center=1, right=1, maxLPS=1, maxLPSIdx=0;
        
    for (int i = 1; i < n; i++) {
        if (i < right)
            lps[i] = min(lps[2*center - i], right-i);

        while (i-lps[i] > 0 && i+lps[i] < n-1 && ((i+lps[i]+1)%2 == 0 || s[(i+lps[i]+1)/2] == s[(i-lps[i]-1)/2]))
            lps[i]++;

        if (lps[i] > maxLPS) {
            maxLPS = lps[i];
            maxLPSIdx = i;
        }
        
        if (i + lps[i] > right) {
            center = i;
            right = i + lps[i];
        }
    }
        
    int start = (maxLPSIdx - maxLPS)/2;
    return s.substr(start, maxLPS);
}

// 法二: dp (n^2)
string longestPalindrome(string s) {
    int n = s.length();
    vector<vector<bool>> dp(n+1, vector<bool>(n+1));
    for (int len = 1; len <= n; ++len)
        for (int i = 0; i+len-1 < n; ++i)
            if (s[i] == s[i+len-1]) {
                dp[i][i+len] = dp[i+1][i+len-1] + (len == 1 ? 1 : 2);
                ans = max(ans, dp[i][i+len]);
            }
}
```

[manacher explan](https://medium.com/hoskiss-stand/manacher-299cf75db97e)
[manacher code](https://cppext.com/?p=1743)
[dp](https://clay-atlas.com/blog/2021/01/03/leetcode-cn-5-longest-palindromic-substring/)
