//
// Created by 叶锋 on 2021/1/23.
//

#include "1409.h"


vector<int> processQueries(vector<int>& queries, int m){
    vector<int> p={};
    vector<int> result={};
    for(int i=1;i<=m;i++){
        p.push_back(i);
    }
    for(int i=0;i<queries.size();i++){
        auto it = find(p.begin(), p.end(), queries[i]);
        result.push_back(it-p.begin());
        p.erase(it);
        p.insert(p.begin(), queries[i]);
    }
    return result;
}

void Test1409(){
    vector<int >queries = {3,1,2,1};
    int m = 5;
    auto result = processQueries(queries,m);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    std::cout<<std::endl;
}