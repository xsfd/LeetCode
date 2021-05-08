//
// Created by 叶锋 on 2021/1/31.
//

#include "0134.h"
#include <numeric>  // vector 求和

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
  if (accumulate(gas.begin(), gas.end(), 0) <
      accumulate(cost.begin(), cost.end(), 0)) {
    return -1;
  }
  vector<int> one_cost(cost.size(),0);
  for(int i=0;i<one_cost.size();i++){
    one_cost[i] = gas[i]-cost[i];
  }
  return 1;

}

// -2,-2,-2,3,3
void Test0134() {
  vector<int> gas = {1, 2, 3, 4, 5};
  vector<int> cost = {3, 4, 5, 1, 2};
  int result = canCompleteCircuit(gas, cost);
  std::cout << result << std::endl;
}