#include "Solution.hpp" // header in local directory

using namespace leetcode;
using namespace std;

bool Solution::uniqueOccurrences(vector<int> &arr) 
{
    unordered_map<int, int> map;
    unordered_set<int> occurences;

    for (auto value : arr)
        map[value]++;
    
    for (auto itr : map)
        occurences.insert(itr.second);

    return map.size() == occurences.size();
}

bool Solution::halvesAreAlike(string s) 
{
    int vowels_r = 0;
    int vowels_l = 0;
    const set<char> vowels = {'a','e','i','o','u','A', 'E', 'I', 'O', 'U'};
    for (int i = 0; i < (int)s.size()/2; i++)
    {
        if(vowels.count(s.at(i)) > 0)
            vowels_l++;

        if(vowels.count(s.at(s.size()-i-1)) > 0)
            vowels_r++;
    }

    return vowels_r == vowels_l;        
}

bool Solution::closeStrings(string word1, string word2) {
    unordered_map<char,int> char_w1;
    unordered_map<char,int> char_w2;

    if(word1.size() != word2.size())
        return false;

    for (auto c : word1)
        char_w1[c]++;

    for (auto c : word2)
        char_w2[c]++;

    if(char_w1.size() != char_w2.size())
        return false;

    return true;
}