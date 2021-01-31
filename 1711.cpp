//
// Created by 叶锋 on 2021/1/23.
//

#include "1711.h"
#include <unordered_map>


int countPairs(vector<int>& deliciousness){
    const int MOD = 1e9 + 7;
    unordered_map<int,int> memo;
    long ans = 0;
    for (int i = 0;i < deliciousness.size();++i){
        for (int j = 0;j < 22;++j){
            int target = pow(2,j);
            if (target - deliciousness[i] < 0) continue;
            if (memo.count(target - deliciousness[i])){
                ans += memo[target - deliciousness[i]];
            }
        }
        ++memo[deliciousness[i]];
    }
    ans %= MOD;
    return ans;
}


void Test1711(){
    vector<int >deliciousness={1,1,1,3,3,3,7};
    int result = countPairs(deliciousness);
    std::cout<<result<<std::endl;
}