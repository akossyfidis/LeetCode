#include "Solution.hpp" // header in local directory

using namespace leetcode;
using namespace std;

bool Solution::findParent(int n, vector<int>& leftChild, vector<int>& rightChild) {
    for (int i=0; i < n; i++) {
        int left = leftChild[i], right=rightChild[i];
        if (left != -1) {
            if (parent.count(left) != 0 || left == i) {
                return 0;
            }
            parent[left] = i;
        }
        if (right != -1) {
            if (parent.count(right) != 0 || right == i) {
                return 0;
            }
            parent[right] = i;
        }
    }
    return 1;
}

int Solution::findRoot(int i) {
    if (parent.count(i)==0) 
        return i;
    
    if (root[i]!=-1) return root[i];
    root[i]=-2;
    return root[i]=findRoot(parent[i]);
}

bool Solution::validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
    bool yes = findParent(n, leftChild, rightChild);
    if (!yes) return 0;
    root.assign(n, -1);
    int R0=findRoot(0);
    if (R0==-2||parent.count(R0)) return 0;
    #pragma unroll
    for (int i = 0; i<n; i++) {
        if (root[i]==-1) {
            int R=findRoot(i);
            if (R==-2||R!=R0||parent.count(R)) return 0;
        }
    }
    return 1;
}