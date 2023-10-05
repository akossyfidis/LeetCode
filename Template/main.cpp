// my_program.cpp
#include "Solution.hpp"

using namespace leetcode;

int main()
{
    std::vector<int> vec = {5,7,3,0,1,1,4,5,7,4};
    Solution mySolution;

    string word1 = "abd";
    string word2 = "bca";

    bool res;

    res = mySolution.closeStrings(word1, word2);
    
    cout << res << endl;


    return 0;
}