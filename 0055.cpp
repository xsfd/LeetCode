//
// Created by 叶锋 on 2021/1/31.
//

#include "0055.h"

bool canJump(vector<int> &nums) {
  int max_item = nums[0];
  for (int i = 0; i < nums.size(); i++) {
    if (max_item + i >= nums.size() - 1) {
      return true;
    }
    if (nums[i] == 0 && max_item == 0) {
      return false;
    }
    max_item = max(nums[i], max_item);
    max_item -= 1;
  }
  return false;
}

void Test0055() {
  vector<int> nums_1 = {2, 3, 1, 1, 4};
  vector<int> nums_2 = {0, 2, 3};
  bool result_1 = canJump(nums_1);
  bool result_2 = canJump(nums_2);
  std::cout << result_1 << std::endl;
  std::cout << result_2 << std::endl;
}