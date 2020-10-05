class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        
        string ans;
        int len = s.length();
        int steps = (numRows-1)*2;
        
        for (int i = 0; steps - 2*i >= 0 && i < len; ++i) {
            ans += s[i];
            for (int j = i; j < len;) {
                int upper = 2*i;
                int lower = steps - 2*i;
                
                j += steps - 2*i;
                if (steps - 2*i && j < len)
                    ans += s[j];

                j += 2*i;
                if (upper && j < len)
                    ans += s[j];
            }
        }
        return ans;
    }
};