//
// Created by yf on 11/15/20.
//

#include "0005.h"
// todo: 待完成

// https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zhong-xin-kuo-san-dong-tai-gui-hua-by-liweiwei1419/

bool Palindrome(string s){
    int len= s.size();
    bool res = false;
    int i=0;
//    if(len%2==0){
//        while(i<len/2){
//            if()
//        }
//    }
    return res;
}

string longestPalindrome(string s){
    string res = "";
    if(s.empty())return res;
    int i=0,j=0;
    while(j<s.size()){
        if(Palindrome(s.substr(i,j)))
    }


    while(j<s.size()){

    }




    return res;
}
void test0005(){
    string s="abcdef";
    string result = longestPalindrome(s);
    std::cout<<"test0003 result: "<<result<<std::endl;
}