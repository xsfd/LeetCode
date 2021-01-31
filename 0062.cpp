//
// Created by 叶锋 on 2021/1/24.
//

#include "0062.h"

// 回溯法： 直接使用回溯法会导致超时
void fun(int i, int j, int m, int n, int &result) {
    if (i == m - 1 || j == n - 1) {
        result++;
        return;
    }
    fun(i + 1, j, m, n, result);
    fun(i, j + 1, m, n, result);
}

// 回溯法
int uniquePaths_1(int m, int n) {
    int result = 0;
    fun(0, 0, m, n, result);
    return result;
}

// 动态规划,注意动态规划的初始化问题以及动态规划的状态公式
// 本题中的边缘全部初始化成 1 ，而不是 0
// pb[i][j]=pb[i-1][j]+pb[i][j-1]
int uniquePaths_2(int m, int n) {
    vector<vector<int>> pb(m, vector<int>(n, 1));
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            pb[i][j] = pb[i - 1][j] + pb[i][j - 1];
        }
    }
    return pb[m - 1][n - 1];
}

void Test0062() {
    int m = 3, n = 7;
    auto result_1 = uniquePaths_1(m, n);
    std::cout << result_1 << std::endl;
    auto result_2 = uniquePaths_2(m, n);
    std::cout << result_2 << std::endl;
}