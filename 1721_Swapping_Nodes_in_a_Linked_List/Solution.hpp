#include <vector>
#include <iostream> // header in standard library
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>

using namespace std;

namespace leetcode
{
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    class Solution
    {
        public:
            ListNode* swapNodes(ListNode* head, int k);
    };
}