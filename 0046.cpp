//
// Created by 叶锋 on 2021/1/24.
//

#include "0046.h"

void fun(vector<vector<int>> &result, vector<int> &res, vector<int> &nums,
         vector<bool> &used) {
  if (nums.size() == res.size()) {
    result.push_back(res);
    return;
  }
  for (int i = 0; i < nums.size(); i++) {
    if (used[i]) {
      continue;
    }
    int cur_num = nums[i];
    res.push_back(cur_num);
    used[i] = true;
    fun(result, res, nums, used);
    res.pop_back();
    used[i] = false;
  }
}

vector<vector<int>> permute(vector<int> &nums) {
  vector<vector<int>> result;
  vector<int> res;
  vector<bool> used(nums.size(), false);
  fun(result, res, nums, used);
  return result;
}

void Test0046() {
  vector<int> nums = {1, 2, 3};
  auto result = permute(nums);
  for (auto &i : result) {
    for (int j : i) {
      std::cout << j << "\t";
    }
    std::cout << std::endl;
  }
}