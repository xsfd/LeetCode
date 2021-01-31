//
// Created by 叶锋 on 2021/1/23.
//

#include "1169.h"


#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>


using namespace std;

// name, time, money, city

vector<string> StrSpilt(string str) {
    vector<string> res;
    const char *split_ch = ",";
    auto p = strtok(const_cast<char *>(str.c_str()), split_ch);
    while (p) {
        res.push_back(string(p));
        p = strtok(NULL, split_ch);
    }
    return res;
}

bool Timetrue(string str1, string str2) {
    if (abs(atoi(str1.c_str()) - stoi(str2)) <= 60) {
        return false;
    } else { return true; }
}

// 每次循环的时候只对第 i 个元素进行处理
vector<string> invalidTransactions(vector<string> &transactions) {
    vector<string> result;
    vector<vector<string>> transactions_split;
    for (int i = 0; i < transactions.size(); i++) {
        transactions_split.push_back(StrSpilt(transactions[i]));
    }
    for (int i = 0; i < transactions_split.size(); i++) {
        if (atoi(transactions_split[i][2].c_str()) > 1000) {
            result.push_back(transactions[i]);
            continue;
        }
        if (find(result.begin(), result.end(), transactions[i]) != result.end()) {
            result.push_back(transactions[i]);
            continue;
        }
        for (int j = 0; j < transactions_split.size(); j++) {
            if (i == j) continue;
            if (transactions_split[i][0] == transactions_split[j][0] &&
                transactions_split[i][3] != transactions_split[j][3] &&
                !Timetrue(transactions_split[i][1], transactions_split[j][1])) {
                if (find(result.begin(), result.end(), transactions[i]) == result.end()) {
                    result.push_back(transactions[i]);
                }
            }

        }
    }
    return result;
}


void Test1169() {
    vector<string> transactions = {"alice,20,800,mtv", "bob,50,1200,mtv", "alice,20,800,mtv", "alice,50,1200,mtv",
                                   "alice,20,800,mtv", "alice,50,100,beijing"};
    auto result = invalidTransactions(transactions);
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << std::endl;
    }
}