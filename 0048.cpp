//
// Created by 叶锋 on 2021/1/24.
//

#include "0048.h"

//   i,j             j,n-i
//  n-j,i           n-i,n-j
void swap_num(vector<vector<int>> &matrix, int i, int j) {
  auto len = matrix.size() - 1;
  int temp = matrix[i][j];
  matrix[i][j] = matrix[len - j][i];
  matrix[len - j][i] = matrix[len - i][len - j];
  matrix[len - i][len - j] = matrix[j][len - i];
  matrix[j][len - i] = temp;
}

void rotate(vector<vector<int>> &matrix) {
  int len = matrix.size();
  int loop_count = len / 2;
  for (int i = 0; i < loop_count; i++) {    // 2
    for (int j = i; j < len - i - 1; j++) { // 3
      swap_num(matrix, i, j);
    }
  }
}

void Test0048() {
  vector<vector<int>> matrix = {
      {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
  rotate(matrix);
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
