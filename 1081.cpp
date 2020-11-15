//
// Created by yf on 11/15/20.
//

#include "1081.h"

//todo: 贪心算法
string smallestSubsequence(string s) {
    string res = "";
    for (int i = 0; i < s.size(); i++) {
        auto ch = s[i];
        auto mm = find(s.begin() + i, s.end(), res[res.size() - 1]);
        auto ch_find_in_res = find(res.begin(), res.end(), ch);
        if (ch_find_in_res == res.end()) {
            while (!res.empty() && ch < res[res.size() - 1] &&
                   find(s.begin() + i, s.end(), res[res.size() - 1]) != s.end()) {
                res.erase(res.size()-1);
            }
            res += ch;
        }
    }
    return res;
}
void test1081() {
    string s = "bcabc";
    string result = smallestSubsequence(s);
    cout << "test1081 result: " << result << endl;
}
