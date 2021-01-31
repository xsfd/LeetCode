//
// Created by 叶锋 on 2021/1/23.
//

#include "0289.h"

int GetLeft(vector<vector<int>> &board, int i, int j) {
    if (j == 0) return 0;
    return board[i][j - 1] > 0 ? 1 : 0;
}

int GetRight(vector<vector<int>> &board, int i, int j) {
    if (j == board[i].size() - 1) return 0;
    return board[i][j + 1] > 0 ? 1 : 0;
}

int GetUpLeft(vector<vector<int>> &board, int i, int j) {
    if (i == 0 || j == 0) return 0;
    return board[i - 1][j - 1] > 0 ? 1 : 0;
}

int GetUpRight(vector<vector<int>> &board, int i, int j) {
    if (i == 0 || j == board[i].size() - 1) return 0;
    return board[i - 1][j + 1] > 0 ? 1 : 0;
}

int GetUp(vector<vector<int>> &board, int i, int j) {
    if (i == 0) return 0;
    return board[i - 1][j] > 0 ? 1 : 0;
}

int GetDown(vector<vector<int>> &board, int i, int j) {
    if (i == board.size() - 1) return 0;
    return board[i + 1][j] > 0 ? 1 : 0;
}

int GetDownLeft(vector<vector<int>> &board, int i, int j) {
    if (i == board.size() - 1 || j == 0) return 0;
    return board[i + 1][j - 1] > 0 ? 1 : 0;
}

int GetDownRight(vector<vector<int>> &board, int i, int j) {
    if (i == board.size() - 1 || j == board[i].size() - 1) return 0;
    return board[i + 1][j + 1] > 0 ? 1 : 0;
}

int GetAll(vector<vector<int>> &board, int i, int j) {
    return GetLeft(board, i, j) + GetRight(board, i, j) +
           GetUpLeft(board, i, j) + GetUpRight(board, i, j) + GetUp(board, i, j) +
           GetDown(board, i, j) + GetDownLeft(board, i, j) + GetDownRight(board, i, j);
}

// old status: 0,1
// new status: 1,-1, 10,11
// status <= 0 dead
// status > 0 live
// 0   : 0
// 1   : 1

// 0->0: -100
// 0->1: -101
// 1->0: 110
// 1->1: 1
void gameOfLife(vector<vector<int>> &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] > 0) {
                if (GetAll(board, i, j) < 2) {
                    board[i][j] = 110;  // 1->0
                } else if (GetAll(board, i, j) == 2 || GetAll(board, i, j) == 3) {
                    board[i][j] = 1;   // 1->1
                } else if (GetAll(board, i, j) > 3) {
                    board[i][j] = 110;  // 1->0
                }
            } else {
                if (GetAll(board, i, j) == 3) {
                    board[i][j] = -101;  // 0->1
                } else {
                    board[i][j] = -100; // 0->0
                }
            }
        }
    }
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] ==-101||board[i][j] ==1) {
                board[i][j] = 1;
            } else {
                board[i][j] = 0;
            }
        }
    }
}

void Test0289() {
    vector<vector<int>> board = {{0, 1, 0},
                                 {0, 0, 1},
                                 {1, 1, 1},
                                 {0, 0, 0}};
    gameOfLife(board);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// [[0,0,0]
// [1,0,1]
// [0,1,1]
// [0,1,0]]
