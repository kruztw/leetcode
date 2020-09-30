#include <iostream>

using namespace std;

string preProcess(string s) {
    int s_len = s.length();
    if (s_len == 0)
        return "^$";

    string ret = "^";
    for (int i = 0; i < s_len; i++){
        ret += "#";
        ret += s[i];
    }
    ret += "#$";

    return ret;
}


// 馬拉車算法
string Manacher(string _s) {
    string s = preProcess(_s);
    int s_len = s.length();
    int P[s_len] = {};
    int C = 0,  R = 0;

    for (int i = 1; i < s_len - 1; i++) {
        // i_mirror: i 的對稱點
        int i_mirror = 2 * C - i;

        // 邊界內 (R: 範圍最右邊)
        // if P[i] = R-i : case 1
        // if P[i] = P[i_mirror] : 直接對稱, 或 case 2
        if (i < R)
            P[i] = min(R - i, P[i_mirror]);
        else
            P[i] = 0; // case 3

        // 擴散法  (P[i] 為已經算好的部份, 這就是讓整體為 O(n) 的關鍵)
        while (s[P[i]+i+1] == s[i-1-P[i]])
            P[i]++;

        // 如果最右側超過原始範圍邊界, 則更新中心點和半徑
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }

    }

    // 找出 P 的最大值
    int maxLen = 0;
    int center = 0;
    for (int i = 1; i < s_len - 1; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            center = i;
        }
    }

    int start = (center - maxLen) / 2; //最开始讲的求原字符串下标
    return _s.substr(start, maxLen);
}

int main() {
    cout << Manacher("cbcbcbde") << endl;
}