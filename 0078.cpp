//
// Created by 叶锋 on 2021/1/23.
//

#include "0078.h"

// 回溯法，注意：添加到res中的元素要及时进行pop出来，进行下一轮的计算。
void fun(vector<int> nums,vector<int> res,vector<vector<int>> &result,int i){
    if(nums.size()==i){
        result.push_back(res);
        return;
    }
    res.push_back(nums[i]);
    fun(nums,res,result,i+1);
    res.pop_back();
    fun(nums,res,result,i+1);
}

vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> result;
    vector<int> res={};
    fun(nums,res,result,0);
    return result;
}

void Test0078(){
    vector<int> nums = {1,2,3};
    auto res = subsets(nums);
    for(int i=0;i<res.size();i++){
        if(res[i].size()==0){
            cout<<"[]";
        }
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<"  ";
        }
        cout<<endl;
    }
}