//
// Created by yf on 11/14/20.
//

#include "0044.h"


// s 是完整的字符串，p是带符号的字符串
// s.size() >= p.size()
// todo: 该代码有问题，待完成
bool isMatch(string s, string p) {
    if (s.empty() && p.empty()) return true;
    if (s.empty() || p.empty()) return false;
    int istart = -1, jstart = -1;
    for (int i = 0, j = 0; i < s.size(); i++) {
        if (s[i] == p[j] || p[j] == '?') {
            i++;
            j++;
        } else if (p[j] == '*') {
            if (j == p.size() - 1) return true;
            if (j < p.size()){
                istart = i;
                jstart = j;
            }
        } else if(istart>=0){
            istart++;
            i=istart;
            j= jstart+1;
        } else {
            return false;
        }
    }
    return true;
}
void test0044() {
    string s = "";
    string p = "";
    bool result = isMatch(s, p);
    cout << "test0044 result: " << result << endl;
}
