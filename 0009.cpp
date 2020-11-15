//
// Created by yf on 10/31/20.
//

#include "0009.h"

bool isPalindrome(int x) {
    if(x<0) return false;
    int old = x;
    long long res = 0;
    while(x){
        int num = x%10;
        res = res*10+num;
        x/=10;
    }
    if(res==old)return true;
    return false;
}


void test0009(){
    int x = 101;
    int res = isPalindrome(x);
    std::cout<<res<<std::endl;
}