#include "Solution.hpp" // header in local directory

using namespace leetcode;
using namespace std;

vector<int> Solution::majorityElement(vector<int>& nums) {

    unordered_map<int,int> values;
    vector<int> output;

    for(auto num : nums)
        values[num]++;

    for(auto v : values) {
        if(v.second > floor(nums.size()/3))
            output.push_back(v.first);  
    }
    
    return output;
}