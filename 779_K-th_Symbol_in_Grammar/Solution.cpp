#include "Solution.hpp" // header in local directory

using namespace leetcode;
using namespace std;

int Solution::kthGrammar(int n, int k) {
    bool isEqual = true; 
    n = pow(2, n - 1);
    while (n != 1) {
        n /= 2;
        if (k > n) {
            k -= n;
            isEqual = !isEqual;
        }
    }
    return ((isEqual) ? 0 : 1) ;
}
