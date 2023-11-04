#include "Solution.hpp" // header in local directory

using namespace leetcode;
using namespace std;

vector<string> Solution::buildArray(vector<int>& target, int n) {
    vector<string> ans;
    int index = 0, size = target.size();
    for(int i = 1; i <= n; i++) {
        if(i == target[index]) {
            index++;
            ans.push_back("Push");
        }
        else {
            ans.push_back("Push");
            ans.push_back("Pop");
        }
        if(index == size) {
            break;
        }
    }
    return ans;
}
