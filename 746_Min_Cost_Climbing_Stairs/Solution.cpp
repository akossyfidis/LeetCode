#include "Solution.hpp" // header in local directory

using namespace leetcode;
using namespace std;

int Solution::minCostClimbingStairs(vector<int>& cost) {
    for(int i = 2; i < cost.size(); i++){
        cost[i] = cost[i] + min(cost[i-1], cost[i-2]);
    }
    return min(cost[cost.size() - 1],cost[cost.size() - 2]);
}