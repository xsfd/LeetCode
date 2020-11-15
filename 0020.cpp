//
// Created by yf on 11/13/20.
//

#include "0020.h"
#include <map>
#include <stack>

//todo: map 类相关方法的使用； stack 的使用
bool isValid(string s) {
    std::map<char, char> pairs{{'}', '{'}, {')', '('}, {']', '['}};
    stack<char> str;
    for (size_t i = 0; i < s.size(); i++) {
        if (str.empty()||!(pairs.count(s[i]))) {
            str.push(s[i]);
        }
        else if (str.top() == pairs[s[i]]) {
            str.pop();
        } else {
            str.push(s[i]);
        }
    }
    if (str.empty()) {
        return true;
    } else {
        return false;
    }
}


void test0020() {
    string s = "{[]}";
    bool result = isValid(s);
    cout << "test0020 result: " << result << endl;
}
