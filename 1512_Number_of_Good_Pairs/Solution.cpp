#include "Solution.hpp" // header in local directory

using namespace leetcode;
using namespace std;

int Solution::numIdenticalPairs(vector<int>& nums) {
    int pairs = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i+1; j < nums.size(); j++) 
        {
            if(nums[i] == nums[j])
            {
                pairs++;
            }
        }
    }

    return pairs;
}