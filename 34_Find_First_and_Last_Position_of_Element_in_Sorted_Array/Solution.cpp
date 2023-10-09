#include "Solution.hpp" // header in local directory

using namespace leetcode;
using namespace std;

vector<int> Solution::searchRange(vector<int>& nums, int target) {
    if(nums.size() < 1) return {-1, -1};

    if (binary_search (nums.begin(), nums.end(), target)) {
        auto low = lower_bound (nums.begin(), nums.end(), target);
        auto up = upper_bound (nums.begin(), nums.end(), target);
        vector<int> out = {(int)(low - nums.begin()), (int)(up - nums.begin()-1)};
        return out; 
    }
    return {-1, -1};
}