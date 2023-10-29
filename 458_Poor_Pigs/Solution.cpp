#include "Solution.hpp" // header in local directory

using namespace leetcode;
using namespace std;

int Solution::poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return ceil(log2(buckets)/log2(int(minutesToTest/minutesToDie)+1));
    }
