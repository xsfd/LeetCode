//
// Created by yf on 11/15/20.
//

#include "0003.h"

//todo: 滑窗法
int lengthOfLongestSubstring(string s) {
    if (s.empty()) return 0;
    int len = s.size();
    int res = 0;
    vector<int> pairs(256, 0);
    int i = 0, j = 0;
    int cur=0;
    while (j < len) {
        if (pairs[s[j]] < 1) {
            pairs[s[j]]++;
            j++;
        } else if (pairs[s[j]] >= 1) {
            pairs[s[i]]--;
            if (cur > res) { res = cur; }
            i++;
        }
        cur=j-i;
    }
    if(cur>res)return cur;
    return res;
}

void test0003() {
    string s = "abcabcabc";
    int result = lengthOfLongestSubstring(s);
    std::cout << "test0003 result: " << result << std::endl;
}