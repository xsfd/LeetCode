//
// Created by yf on 10/31/20.
//

#include "0014.h"

string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()) return "";
    string res = "";
    int min_lenth = strs[0].size();
    for(int i=0;i<strs.size();i++){
        if(strs[i].size()<min_lenth){
            min_lenth = strs[i].size();
        }
    }
    for(int i=0;i<min_lenth;i++){
        auto temp = strs[0][i];
        bool same = true;
        for(int j=0;j<strs.size();j++){
            if(temp!=strs[j][i]){
                same= false;
            }
        }
        if(same){
            res+=temp;
        }else{
            return res;
        }
    }


    return res;
}

void test0014(){
//    vector<string> strs = {"flower","flow","flight"};
    vector<string> strs = {};
    auto res = longestCommonPrefix(strs);
    std::cout<<"test0014 result: "<<res<<std::endl;
}