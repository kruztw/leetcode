class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if (!len)
            return 0;
        
        int ascii[0x80] = {};
        int start = 1, ans = 1;
        for (int i = 0; i<len; ++i){
            if (ascii[s[i]] >= start) {
                ans = max(ans, i+1-start);
                start = ascii[s[i]] + 1;
            }
            ascii[s[i]] = i+1;
        }

        ans = max(ans, len-start+1);
        return ans;
    }
};
