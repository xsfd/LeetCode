//
// Created by yf on 11/2/20.
//

#ifndef TEST_V0_0104_H
#define TEST_V0_0104_H

# include <iostream>
#include <stack>
#include <vector>
#include "math.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode root);
void test0104();

#endif //TEST_V0_0104_H
