//
// Created by 叶锋 on 2021/1/24.
//

#include "0042.h"

int trap(vector<int> &height) {
  if (height.size() == 0) {
    return 0;
  }
  auto it_max_height =
      max_element(height.begin(), height.end()) - height.begin();
  int max_left = 0, max_right = 0;
  int res = 0;
  for (int i = 0; i < it_max_height; i++) {
    max_left = height[i] > max_left ? height[i] : max_left;
    res += max_left - height[i];
  }
  for (int i = height.size() - 1; i > it_max_height; i--) {
    max_right = height[i] > max_right ? height[i] : max_right;
    res += max_right - height[i];
  }
  return res;
}

void Test0042() {
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int result = trap(height);
  std::cout << result << std::endl;
}