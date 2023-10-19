#include "Solution.hpp" // header in local directory

using namespace leetcode;
using namespace std;

bool Solution::backspaceCompare(string s, string t) {
    string s1 = "", s2 = "";
    for(auto c : s){
        if(c != '#') s1+=c;
        else if(!s1.empty()) s1.pop_back();
    }

    for(auto c : t){
        if(c != '#') s2+=c;
        else if(!s2.empty()) s2.pop_back();
    }
    return (s1 == s2); 
}