#include "Solution.hpp" // header in local directory

using namespace leetcode;
using namespace std;

vector<int> Solution::largestValues(TreeNode* root) {
    if(root == nullptr) return {};
    vector<int> ans;
    vector<TreeNode*> row(1, root);
    while(true)
    {   
        vector<TreeNode*> next;
        int maxi = INT_MIN;
        for(auto n : row)
        {
            maxi = max(maxi, n->val);
            if(n->left != nullptr)
                next.push_back(n->left);                   
            if(n->right != nullptr)
                next.push_back(n->right);
        }
        ans.push_back(maxi);
        if(next.size() < 1) return ans;
        else row = next;  
    }
}
