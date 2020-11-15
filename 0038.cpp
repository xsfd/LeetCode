//
// Created by yf on 11/14/20.
//

#include "0038.h"
#include <sstream>
#include <stack>

/*

1.     1
2.     11
3.     21
4.     1211
5.     111221

 * */

// todo：数字与字符串之间的相关转化问题
string num2str(double i) {

    stringstream ss;
    ss << i;
    return ss.str();
}


string countAndSay(int n) {
    vector<string> s_vec = {"1", "11"};
    for (int i = s_vec.size() - 1; i < n; i++) {
        string s = s_vec[i];
        auto first = 0;
        auto second = 1;
        string temp = "";
        while (second < s.size()) {
            if (s[first] == s[second] && second + 1 == s.size()) {
                temp = temp + num2str(second - first+1) + s[first];
                second++;
            } else if (s[first] == s[second]) {
                second++;
            }else if (s[first] != s[second]&&second + 1 == s.size()) {
                temp = temp + num2str(second - first) + s[first];
                first = second;
                second++;
                temp=temp+"1"+s[first];
            }
            else if (s[first] != s[second]) {
                temp = temp + num2str(second - first) + s[first];
                first = second;
                second++;
            }
        }
        s_vec.push_back(temp);
    }
    return s_vec[n - 1];
}
void test0038() {
    int n = 5;
    string s = countAndSay(n);
    cout << "test0014 result: " << s << endl;
}