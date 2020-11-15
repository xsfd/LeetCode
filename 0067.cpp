//
// Created by yf on 11/1/20.
//

#include "0067.h"


string addBinary(string a, string b) {
    string res = "";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int len = max(a.size(), b.size());
    int add = 0;
    for (int i = 0; i < len; i++) {
        int temp = 0;
        if (i >= a.size()) {
            temp = b[i] - '0' + add;
            add = temp/2;
            temp %= 2;
            res+=temp+'0';
            continue;
        }
        if (i >= b.size()) {
            temp = a[i] - '0' + add;
            add = temp/2;
            temp %= 2;
            res+=temp+'0';
            continue;
        }
        temp = a[i]-'0'+b[i]-'0'+add;
        add=temp/2;
        temp%=2;
        res+=temp+'0';
    }
    if(add==1){
        res+='1';
    }
    reverse(res.begin(),res.end());
    return res;
}

void test0067() {
    string a = "1010";
    string b = "1011";
    string res = addBinary(a, b);
    cout << "test0067 result: " << res << endl;
}