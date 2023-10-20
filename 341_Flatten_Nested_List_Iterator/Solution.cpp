#include "Solution.hpp" // header in local directory

using namespace leetcode;
using namespace std;

NestedIterator::NestedIterator(vector<NestedInteger> &nestedList) {
    flatten(nestedList);
}

void NestedIterator::flatten(vector<NestedInteger> &nestedList) {
    for(auto l : nestedList) {
        if(l.isInteger()) f.push(l.getInteger());
        else flatten(l.getList());
    }
}
    
int NestedIterator::next() {
    int out = f.front();
    f.pop();
    return out;
}
    
bool NestedIterator::hasNext() {
    return (!f.empty());
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */